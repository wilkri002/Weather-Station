void connectToWifi(){                  

  WiFi.begin(WLAN_SSID, WLAN_PASS);         //start wifi
  
  int loginTimer = millis()/1000;             //
  while (WiFi.status() != WL_CONNECTED) {     //connect to wifi
    delay(500);                               //
    if(loginTimer + 20 <= millis()/1000){     //if it takes too long, restart
      resetFunc();                            //
      }
  }
}
