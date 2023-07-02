#include <Arduino.h>
#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <DNSServer.h>

IPAddress apIP(192, 168, 1, 1);
WebServer webServer(80);
DNSServer dnsServer;

#define BUF_SIZE 4000

char serial_buffer[BUF_SIZE + 1];
int serial_buffer_idx = 0;
int serial_buffer_todo = 0;

void add_to_serial_buffer(char input)
{
  if (serial_buffer_todo < BUF_SIZE)
  {
    int idx = serial_buffer_idx + serial_buffer_todo;
    if (idx > BUF_SIZE)
      idx -= (BUF_SIZE +1);

    serial_buffer[idx] = input;
    serial_buffer_todo++;
  }
}

void handleRoot()
{

  webServer.send(200, "text/html", responseHTML);

  if (webServer.hasArg("sequence"))
  {
      if (webServer.arg("sequence").length() >= 1){

      char sequence_data[10];
      memset(sequence_data, '\0', sizeof(sequence_data));
      strncpy(sequence_data, webServer.arg("sequence").c_str(), 8);
      
      add_to_serial_buffer(0x02);
      add_to_serial_buffer(0x0c);
      for (int i = 0; i < webServer.arg("sequence").length(); i++)
      {
        add_to_serial_buffer(sequence_data[i]);
      }
      add_to_serial_buffer(0x10);
      }
  }

  
  if (webServer.hasArg("time"))
  {

    
    if (webServer.arg("time").length() >= 8)
    {
      char update_time_data[10];
      memset(update_time_data, '\0', sizeof(update_time_data));
      strncpy(update_time_data, webServer.arg("time").c_str(), 8);

      add_to_serial_buffer(0x02);
      add_to_serial_buffer(0x0F);
      add_to_serial_buffer('1');
      add_to_serial_buffer('2');
      add_to_serial_buffer(0x10);

      // Write AM or PM
      add_to_serial_buffer(update_time_data[6]);
      add_to_serial_buffer(update_time_data[7]);
      add_to_serial_buffer(0x10);

      // Write Hours
      add_to_serial_buffer(update_time_data[0]);
      add_to_serial_buffer(update_time_data[1]);
      add_to_serial_buffer(0x10);

      // Write Minutes
      add_to_serial_buffer(update_time_data[3]);
      add_to_serial_buffer(update_time_data[4]);
      add_to_serial_buffer(0x10);

      // confirm
      add_to_serial_buffer(0x10);
    }
  }

  if (webServer.hasArg("reset"))
  {
    add_to_serial_buffer(0x02);
    add_to_serial_buffer(0x03);
    add_to_serial_buffer('Y');
    add_to_serial_buffer(0x10);
  }

  if (webServer.hasArg("pwr"))
  {
    add_to_serial_buffer(0x1E);
  }

  if (webServer.hasArg("buffer") && webServer.hasArg("slot"))
  {
    if (webServer.arg("buffer").length() < 201 && webServer.arg("slot").length() >= 1)
    {
      char update_txt_slot;
      char update_txt_data[201];
      sscanf(webServer.arg("slot").c_str(), "%c", &update_txt_slot);
      memset(update_txt_data, '\0', sizeof(update_txt_data));
      strncpy(update_txt_data, webServer.arg("buffer").c_str(), webServer.arg("buffer").length());

      add_to_serial_buffer(0x02);
      add_to_serial_buffer(0x0b);
      add_to_serial_buffer(update_txt_slot);
      add_to_serial_buffer(0x09); // clear the slot
      for (int i = 0; i < webServer.arg("buffer").length(); i++)
      {
        add_to_serial_buffer(update_txt_data[i]);
      }

      add_to_serial_buffer(0x10);
    }
  }
}

void server_start()
{
  // save pointer for the async handler

  Serial1.begin(300, SERIAL_8N2);
  Serial.begin(115200);

  // setup wifi
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP("RC880");

  // setup dns for captive portal
  dnsServer.start(53, "*", apIP);

  webServer.onNotFound(handleRoot);

  webServer.begin();

  while (1)
  {
    static uint32_t last_message_time = 0;  //delay a fixed time for each character
    static uint32_t enter_delay = 0;        //delay extra cycles when enter is pressed

    dnsServer.processNextRequest();
    webServer.handleClient();

    if (millis() - last_message_time > 200)
    {
      last_message_time = millis();

      if (serial_buffer_todo > 0 && enter_delay == 0)
      {

        if (serial_buffer[serial_buffer_idx] == 0x10)
        {
          enter_delay = 10;
        }
        Serial1.write(serial_buffer[serial_buffer_idx++]);
        if (serial_buffer_idx > BUF_SIZE)
          serial_buffer_idx = 0;

        serial_buffer_todo--;
      }

      if (enter_delay > 0)
        enter_delay--;
    }
  }
}