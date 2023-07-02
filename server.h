#ifndef _SERVER_H
#define _SERVER_H

void server_start(void);


const char responseHTML[] = R"rawliteral(
<html>
   <head>
      <title>RC880 Control</title>
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <style>
         button {
         height: 30px;
         width: 100px;
         }
         select{
         width: 100%
         }
		 input{
         width: 100%
         }
		#slot{
 width: auto;   
}
      </style>
   </head>
   <body>
      <h2>RC880 Control</h2>
      <table>
         <tr>
            <td>
               <button type="button" onClick="insert_special('gfx_select')">Graphics</button><br>
               <select id="gfx_select">
                  <option value="225">Heart</option>
                  <option value="226">Munch</option>
                  <option value="227">Phone</option>
                  <option value="228">Wheel</option>
                  <option value="229">Ball</option>
                  <option value="230">Plane</option>
                  <option value="231">Ship</option>
                  <option value="232">House</option>
                  <option value="233">Car</option>
               </select>
            </td>
            <td>
               <button type="button" onClick="insert_gfx2()">Graphics 2</button><br>
               <select id="gfx2_select">
                  <option value="A">Bus</option>
                  <option value="B">Bikes</option>
                  <option value="C">Cake</option>
                  <option value="D">Dinner</option>
                  <option value="E">Tree</option>
                  <option value="F">Fruit</option>
                  <option value="G">Gift</option>
                  <option value="H">Helicopter</option>
                  <option value="I">Table</option>
                  <option value="J">Crown</option>
                  <option value="K">Key</option>
                  <option value="L">Flag</option>
                  <option value="M">Music</option>
                  <option value="N">Burger</option>
                  <option value="O">Tools</option>
                  <option value="P">Flower</option>
                  <option value="Q">Shoes</option>
                  <option value="R">Train</option>
                  <option value="S">Sleigh</option>
                  <option value="T">Tea Set</option>
                  <option value="U">Umbrealla</option>
                  <option value="V">TV</option>
                  < value="W">Watch</option>
                  <option value="X">Xmas</option>
                  <option value="Y">Arrow L</option>
                  <option value="Z">Arrow R</option>
               </select>
            </td>
            <td>
               <button type="button" onClick="insert_msg()">Message</button><br>
               <select id="msg_select">
                  <option value="a">Smoking</option>
                  <option value="b">Christmas</option>
                  <option value="c">Thank You</option>
                  <option value="d">America</option>
                  <option value="e">Attention</option>
                  <option value="g">Welcome</option>
                  <option value="h">Happy Hr</option>
                  <option value="i">Don't Drink</option>
                  <option value="j">Open House</option>
                  <option value="k">Sale</option>
               </select>
            </td>
         </tr>
         <tr>
            <td>
               <br><button type="button" onClick="insert_special('style_select')">Style</button><br>
               <select id="style_select">
                  <option value="181">Magic</option>
                  <option value="193">Dazzle</option>
                  <option value="194">Tiny</option>
                  <option value="195">Normal</option>
                  <option value="196">Double</option>
                  <option value="197">Thin</option>
                  <option value="198">Bold</option>
                  <option value="199">V Rainbow</option>
                  <option value="200">Italic</option>
                  <option value="201">Condensed</option>
                  <option value="202">H Rainbow</option>
                  <option value="203">Flash</option>
                  <option value="205">Marquee</option>
               </select>
            </td>
            <td>
               <br><button type="button" onClick="insert_special('other_select')">Other</button><br>
               <select id="other_select">
                  <option value="176">Time</option>
                  <option value="182">Beep</option>
                  <option value="183">Magic Off</option>
                  <option value="184">Up</option>
                  <option value="185">Down</option>
                  <option value="186">Jump</option>
                  <option value="187">Right</option>
                  <option value="188">Crawl</option>
                  <option value="189">Quick</option>
                  <option value="191">Left</option>
               </select>
            </td>
            <td></td>
         </tr>
         <tr>
            <td>
               <br><button type="button" onClick="insert_special('txt_select')">Txt Front</button><br>
               <select id="txt_select">
                  <option value="160">Black</option>
                  <option value="161">Dark Red</option>
                  <option value="162">Orange</option>
                  <option value="163">Red</option>
                  <option value="164">Purple</option>
                  <option value="165">Dark Green</option>
                  <option value="166">Brown</option>
                  <option value="167">Magenta</option>
                  <option value="168">Dark Blue</option>
                  <option value="169">Green</option>
                  <option value="170">Yellow</option>
                  <option value="171">Pink</option>
                  <option value="172">Blue</option>
                  <option value="173">Aqua</option>
                  <option value="174">Cream</option>
                  <option value="175">White</option>
               </select>
            </td>
            <td>
               <br><button type="button" onClick="insert_special('bg_select')">Txt Back</button><br>
               <select id="bg_select">
                  <option value="208">Black</option>
                  <option value="209">Dark Red</option>
                  <option value="210">Orange</option>
                  <option value="211">Red</option>
                  <option value="212">Purple</option>
                  <option value="213">Dark Green</option>
                  <option value="214">Brown</option>
                  <option value="215">Magenta</option>
                  <option value="216">Dark Blue</option>
                  <option value="217">Green</option>
                  <option value="218">Yellow</option>
                  <option value="219">Pink</option>
                  <option value="220">Blue</option>
                  <option value="221">Aqua</option>
                  <option value="222">Cream</option>
                  <option value="223">White</option>
               </select>
            </td>
            <td>
               <br><button type="button" onClick="insert_special('txt_select')">Txt Speed</button><br>
               <select id="txt_select">
                  <option value="144">0 Fast</option>
                  <option value="145">1</option>
                  <option value="146">2</option>
                  <option value="147">3</option>
                  <option value="148">4</option>
                  <option value="149">5</option>
                  <option value="150">6</option>
                  <option value="151">7 Slow</option>
               </select>
            </td>
         </tr>
         <form action="/">
            <tr>
               <td colspan="3"><br>
                  <input type="text" id="payload" name="buffer" value="" placeholder="Message Goes Here">
               </td>
            </tr>
            <tr>
               <td><br><button name="send" type="button" onClick="submit_func(this.form)">Send</button></td>
               <td colspan="2">
                  <br>To Message Slot #
                  <select id="slot" name="slot">
                     <option value="0" selected>0</option>
                     <option value="1">1</option>
                     <option value="2">2</option>
                     <option value="3">3</option>
                     <option value="4">4</option>
                     <option value="5">5</option>
                     <option value="6">6</option>
                     <option value="7">7</option>
                  </select>
               </td>
         </form>
         </tr>
         <tr>
           
               <td> <form action="/"><br><button type="button" onClick="submit_func(this.form)">Set Time</button>
               </td>
               <td><input style="width: 99px;"    name="time" value="">    </form>
               </td><td>
			    <form action="/">
                  <input type="hidden"  style="width: 0px;"  id="payload" name="pwr" value="">
                  <br><button name="pwr" type="button" onClick="submit_func(this.form)">On / Off</button>
            </form>
            </td>
        
         </tr>
         <tr>
    <form action="/">
               <td>
			    
                  <button type="button" onClick="submit_func(this.form)">Display Order</button>
               </td>
               <td>
                  <input style="width: 99px;"  name="sequence" placeholder="01234567">
               </td> </form>
			     <form action="/"><td>
				  
                  <button name="reset" type="button" onClick="submit_func(this.form)">Factory Reset</button><br>
				  <input type="hidden" style="width: 0px;"   id="payload" name="reset" value="">
				  </td>
            </form>
           
         </tr>
   
      </table>
</html>
<script>
   var today = new Date();
   var hours = today.getHours();
   var time = "";
   
   if (hours > 12){
    time = ('0'+(hours - 12)).slice(-2) + ":" + ('0'+today.getMinutes()).slice(-2) + " PM";
   } else {
    time = ('0'+hours).slice(-2) + ":" + ('0'+today.getMinutes()).slice(-2) + " AM";
   }
   document.getElementsByName('time')[0].value = time;
   
   function submit_func(frm) {
   	const response = confirm("Are you sure?");
   	if (response) {
   		frm.submit();
   	} 
   }
   function insert_char(item) {
   var text = document.getElementById('payload');
       text.value += String.fromCharCode(item);
   }
   function insert_special(type) {
   	insert_char(document.getElementById(type).value);
   }
   function insert_msg() {
   	insert_char(133);
   	var text = document.getElementById('payload');
       text.value += document.getElementById('msg_select').value;
   }
   function insert_gfx2() {
   	insert_char(224);
   	var text = document.getElementById('payload');
       text.value += document.getElementById('gfx2_select').value;
   }
</script>
</body>

)rawliteral";



#endif