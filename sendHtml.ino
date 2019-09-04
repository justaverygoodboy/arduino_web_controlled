void sendHTML(float distance) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();
  client.println("<!Doctype html><html><head><meta http-equiv=\"refresh\" content=\"2\"><link href=\"https://cdn.jsdelivr.net/npm/bootstrap@3.3.7/dist/css/bootstrap.min.css\" rel=\"stylesheet\"><style>.wrapper{margin-top:10vh;display:flex;flex-direction:column;align-items:center;justify-content:center}button{margin:10px}</style></head><body><div class=\"wrapper\"><h3>LED SWITCH</h3>");
  client.print(distance);
  client.print("cm");
  client.print("<button class=\"btn btn-success\" onclick=\"turnFan(1)\">Level 1</button><button class=\"btn btn-warning\" onclick=\"turnFan(2)\">Level 2</button><button class=\"btn btn-info\" onclick=\"turnFan(3)\">Level 3</button><button class=\"btn btn-danger\" onclick=\"turnFan(0)\">Turn off</button><button id=\"blink\" onclick=\"turnFan(4)\">blink:on</button></div><script>function turnFan(level){e=document.getElementById(\"blink\");x=new XMLHttpRequest();if(level==1){x.open(\"GET\",\"level1\",true)}else if(level==2){x.open(\"GET\",\"level2\",true)}else if(level==3){x.open(\"GET\",\"level3\",true)}else if(level==0){x.open(\"GET\",\"turnOff\",true)}else if(e.innerHTML.match(\"blink:on\")){e.innerHTML=\"blink:off\";x.open(\"GET\",\"boff\",true)}else{e.innerHTML=\"blink:on\";x.open(\"GET\",\"bon\",true)}x.send();}</script></body></html>");
}
