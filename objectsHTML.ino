/* Place to Store HTML objects that can be called from a function
 * 
 * 
 * 
 * 
 */


   void callHTMLobjects(WiFiClient client){ // function calls all HTML page objects 

            //-------------------------------------------------------------Display Buttons-------------------------

            client.println(" <div class= \"centerBox\">");   // full sized div box everything else goes in


            //----------------------------------------------GPIO 25--------------RED

            client.println(" <div class= \"flexBox\">");   // centered box

            client.println(" <div class= \"leftBox\">");   // div box for input slider/form and text

            client.println(" <div class= \"leftBox\">");     // div box for slider text

            client.println("  Red Level: <span id=\"red\"></span> </br>"); // Print the text box for PWM value;
            client.println("</div>");   // close left box


            client.println(" <div class= \"leftBox\">");
            client.println(" <div class= \"marginBox\"> </br></div>");  // blank box for spacing

            client.println("<form action='/' class=\"inputForm\" method=get >"); // calls form uses IP/port of web page


            //this line for text box input
            // client.println("<input type=\"number\" name=\"redPWM\" min =\"0\" max =\"255\" value= " + R + "  style=\"width: 3em\"><br>");

            //these lines for slider input;
            client.println("<div class=\"slidecontainer\">");
            client.println("<input type=\"range\" name=\"redPWM\" min =\"0\" max =\"255\" value= " + R + " class=\"slider\"");
            client.println("id=\"redRange\"><br>");   // id= "myRange used for javascript (style=\"width: 3em\") remioved
            client.println("</div>");    // close slider box
            client.println("</div>");   // close left box
            client.println("</ br>");   // Start a new line
            client.println(" <div class= \"leftBox\">");

            client.println("<input type=\"submit\" value=\"Apply\">"); // apply box ///</br>  removed from start of box



            client.println("</form>");   // close the form
            client.println("</div>");   // close left box
            client.println("</div>");   // close left box

            client.println(" <div class= \"rightBox\">");   //right div box for On/Off button


            // ---------------Display current state, and ON/OFF buttons for GPIO 25-----------------

            client.println("Red - GPIO 25 - State " + R + "");        //output25State replaced by red PWM might not work coz its an int not a char
            // If the output25State is off, it displays the ON button         // removed <p></p> from printline
            if (output25State == "off") {
              client.println("<p><a href=\"/25/on\"><button class=\"button button2\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/25/off\"><button class=\"button\">ON</button></a></p>");
            }



            client.println("</div>");   // close right box
            client.println(" <div class= \"marginBox\"> </br></div>");  // blank box for spacing
            client.println("</div>");   // close flex box
            //  client.println("</div>");     // close the center box


            // print javascript object;  nothing visible so this can go anywhere?
            client.println("<script> var slider = document.getElementById(\"redRange\");");
            client.println("var output = document.getElementById(\"red\");");
            client.println("output.innerHTML = slider.value;");

            client.println("slider.oninput = function() {output.innerHTML = this.value;}");
            client.println("</script>");

            //----------------------------------------------GPIO 25--------------RED





            //----------------------------------------------GPIO 26--------------Green

            client.println(" <div class= \"marginBox\"> </br></br></div>");  // blank box for spacing

            client.println(" <div class= \"flexBox\">");   // centered box

            client.println(" <div class= \"leftBox\">");   // div box for input slider/form and text

            client.println(" <div class= \"leftBox\">");     // div box for slider text


            // Print the text box for PWM value;   // HIGHLY EXPEREMENTAL
            client.println("Green Level: <span id=\"green\"></span> </br> "); // Print the txt for the PWM value
            client.println("</div>");   // close left box

            client.println(" <div class= \"leftBox\">");
            client.println(" <div class= \"marginBox\"> </br></div>");  // blank box for spacing



            client.println("<form action='/' class=\"inputForm\" method=get >"); //calls form uses IP/port of web page

            /// THis line for Text Box Input
            // client.println("<input type=\"number\" name=\"greenPWM\" min =\"0\" max =\"255\" value= " + G + "  style=\"width: 3em\"><br>");

            //These lines for Slider Input
            //these lines for slider input;
            client.println("<div class=\"slidecontainer\">");
            client.println("<input type=\"range\" name=\"greenPWM\" min =\"0\" max =\"255\" value= " + G + " class=\"slider\"");
            client.println("id=\"greenRange\"><br>");   // id= "myRange used for javascript (style=\"width: 3em\") remioved
            client.println("</div>");    // close slider box
            client.println("</div>");   // close left box
            client.println("</ br>");   // Start a new line
            client.println(" <div class= \"leftBox\">");

            client.println("<input type=\"submit\" value=\"Apply\">"); // apply box ///</br>  removed from start of box


            client.println("</form>");   // close the form
            client.println("</div>");   // close left box
            client.println("</div>");   // close left box

            client.println(" <div class= \"rightBox\">");   //right div box for On/Off button


            // Display current state, and ON/OFF buttons for GPIO 26
            client.println("Green - GPIO 26 - State " + G + "");
            // If the output26State is off, it displays the ON button
            if (output26State == "off") {
              client.println("<p><a href=\"/26/on\"><button class=\"button button2\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/off\"><button class=\"button\">ON</button></a></p>");
            }


            client.println("</div>");   // close right box
            client.println(" <div class= \"marginBox\"> </br></div>");  // blank box for spacing
            client.println("</div>");   // close flex box
            // client.println("</div>");     // close the center box


            // print javascript object;  nothing visible so this can go anywhere?
            client.println("<script> var slider2 = document.getElementById(\"greenRange\");");
            client.println("var output2 = document.getElementById(\"green\");");
            client.println("output2.innerHTML = slider2.value;");

            client.println("slider2.oninput = function() {output2.innerHTML = this.value;}");
            client.println("</script>");


            //----------------------------------------------GPIO 26--------------Green



            //----------------------------------------------GPIO 27--------------Blue
            client.println(" <div class= \"marginBox\"> </br></br></div>");  // blank box for spacing

            client.println(" <div class= \"flexBox\">");   // centered box

            client.println(" <div class= \"leftBox\">");   // div box for input slider/form and text

            client.println(" <div class= \"leftBox\">");     // div box for slider text


            client.println(" Blue Level: <span id=\"blue\"></span> </br>"); // Print the text box for PWM value;
            client.println("</div>");   // close left box

            client.println(" <div class= \"leftBox\">");
            client.println(" <div class= \"marginBox\"> </br></div>");  // blank box for spacing


            client.println("<form action='/' class=\"inputForm\" method=get >"); // calls form uses IP/port of web page


            //this line for text box input
            // client.println("<input type=\"number\" name=\"bluePWM\" min =\"0\" max =\"255\" value= " + B + "  style=\"width: 3em\"><br>");


            //these lines for slider input;
            client.println("<div class=\"slidecontainer\">");
            client.println("<input type=\"range\" name=\"bluePWM\" min =\"0\" max =\"255\" value= " + B + " class=\"slider\"");
            client.println("id=\"blueRange\"><br>");   // id= "myRange used for javascript (style=\"width: 3em\") remioved
            client.println("</div>");    // close slider box
            client.println("</div>");   // close left box
            client.println("</ br>");   // Start a new line
            client.println(" <div class= \"leftBox\">");

            client.println("<input type=\"submit\" value=\"Apply\">"); // apply box ///</br>  removed from start of box



            client.println("</form>");   // close the form
            client.println("</div>");   // close left box
            client.println("</div>");   // close left box

            client.println(" <div class= \"rightBox\">");   //right div box for On/Off button


            // Display current state, and ON/OFF buttons for GPIO 27
            client.println("Blue - GPIO 27 - State " + B + "");
            // If the output27State is off, it displays the ON button
            if (output27State == "off") {
              client.println("<p><a href=\"/27/on\"><button class=\"button button2\">OFF</button></a></p>");
            } else {
              client.println("<p><a href=\"/27/off\"><button class=\"button\">ON</button></a></p>");
            }


            client.println("</div>");   // close right box
            client.println("</div>");   // close flex box
            client.println("</div>");     // close the center box


            // print javascript object;  nothing visible so this can go anywhere?
            client.println("<script> var slider3 = document.getElementById(\"blueRange\");");
            client.println("var output3 = document.getElementById(\"blue\");");
            client.println("output3.innerHTML = slider3.value;");

            client.println("slider3.oninput = function() {output3.innerHTML = this.value;}");
            client.println("</script>");


           //----------------------------------------------GPIO 27--------------Blue



   }
