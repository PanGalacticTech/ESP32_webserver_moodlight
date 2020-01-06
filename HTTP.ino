/*
 * Place to store functions involving HTTP requests
 * 
 * 
 */

// attempt to redirect to our known homepage
 void redirect(WiFiClient client) {
  client.println("HTTP/1.1 307 Temporary Redirect");
  client.println("Location: 192.168.4.1");
  //client.println("Connection: Close");
 // client.println();
 // client.stop();
}



// code to refresh page - UNTESTED.
 void refresh(WiFiClient client){  
client.print("<HEAD>");
client.print("<meta http-equiv=\"refresh\" content=\"0;url=\"192.168.4.1\">");
client.print("</head>");
 }
