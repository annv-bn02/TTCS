#include <PubSubClient.h>
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <ArduinoJson.h>
#include "header.h"
#include "mqtt.h"
//wifi
WiFiClient espClient;
const char* ssid = "artng";
const char* password = "20022002";
//mqtt
PubSubClient client(espClient);
const char *mqtt_broker= "broker.emqx.io";
const char *topic_pub = "Esp32toBroke";
const char *topic_sub = "WebtoBroke";
const char *mqtt_username = "artnguyen";
const char *mqtt_password = "admin";
const int mqtt_port = 1883;

//Json
DynamicJsonDocument data(1024);
char Buffer[1000];
int Length_Buffer;
String Home_Data;
String str_fan_living_room;
String str_light_living_room;
String str_fan_kitchen;
String str_light_kitchen;
String a;
String receive;

mqtt_data_t mqtt_data_send;

void Setup_Wifi() 
{
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void Data_to_Json(mqtt_data_t data_send) 
{
  Home_Data = "{\"temp\":\"" + String(data_send.temp) + "\"," +
                "\"light\":\"" + String(data_send.light) + "\"," +
                "\"gas\":\"" + String(data_send.gas) + "\"," +
                "\"prox\":\"" + String(data_send.prox) + "\"," +
                "\"fan_living_room\":\"" + String(data_send.flag_fan_living_room) + "\"," +
                "\"light_living_room\":\"" + String(data_send.flag_light_living_room) + "\"," +
                "\"fan_kitchen\":\"" + String(data_send.flag_fan_kitchen) + "\"," +
                "\"light_kitchen\":\"" + String(data_send.flag_light_kitchen) + "\"," +
                "\"auto_mode_kitchen\":\"" + String(data_send.auto_mode_kitchen) + "\"," +
                "\"auto_mode_living_room\":\"" + String(data_send.auto_mode_living_room) + "\"," +
                "\"auto_mode_all\":\"" + String(data_send.auto_mode_all) + "\"," +
                "\"door\":\"" + String(data_send.door) + "\"}";
  Length_Buffer = Home_Data.length()+1;
  Home_Data.toCharArray(Buffer,Length_Buffer);
  //Serial.println(Buffer);
}

void Detext(String Str)
{
  deserializeJson(data, Str); 
  if(data["fan_living_room"] != 0 && data["fan_living_room"].as<String>() == "1"){
    flag_fan_living_room = !flag_fan_living_room;
    auto_mode_living_room = 0;
  }
  if(data["light_living_room"] != 0 && data["light_living_room"].as<String>() == "1"){
    flag_light_living_room = !flag_light_living_room;
    auto_mode_living_room = 0;
  }
  if(data["light_kitchen"] != 0 && data["light_kitchen"].as<String>() == "1"){
    flag_light_kitchen = !flag_light_kitchen;
    auto_mode_kitchen = 0;
  }
  if(data["fan_kitchen"] != 0 && data["fan_kitchen"].as<String>() == "1"){
    flag_fan_kitchen = !flag_fan_kitchen;
    auto_mode_kitchen = 0;
  }
  if(data["auto_mode_kitchen"] != 0 && data["auto_mode_kitchen"].as<String>() == "1"){
    auto_mode_kitchen = !auto_mode_kitchen;
  }
  if(data["auto_mode_living_room"] != 0 && data["auto_mode_living_room"].as<String>() == "1"){
    auto_mode_living_room = !auto_mode_living_room;
  }
  if(data["auto_mode_all"] != 0 && data["auto_mode_all"].as<String>() == "1"){
    auto_mode_all = !auto_mode_all;
  }
  if(data["door"] != 0 && data["door"].as<String>() == "1"){
    flag_open_door = OPEN_DOOR;
  }

}

void MQTT_Pub(){
  mqtt_data_send.temp = t;
  mqtt_data_send.gas = gas;
  mqtt_data_send.light = light;
  mqtt_data_send.prox = prox;
  mqtt_data_send.flag_fan_living_room = flag_fan_living_room;
  mqtt_data_send.flag_light_living_room = flag_light_living_room;
  mqtt_data_send.flag_fan_kitchen = flag_fan_kitchen;
  mqtt_data_send.flag_light_kitchen = flag_light_kitchen;
  mqtt_data_send.auto_mode_kitchen = auto_mode_kitchen;
  mqtt_data_send.auto_mode_living_room = auto_mode_living_room;
  mqtt_data_send.auto_mode_all = auto_mode_all;
  mqtt_data_send.door = door;
  Data_to_Json(mqtt_data_send);
	client.publish(topic_pub, Buffer);
  Serial.println("Pub data");
}

void MQTT_Sub()
{
  client.subscribe(topic_sub);
}

void callback(char *topic, byte *payload, unsigned int length)
{
  receive = "";
	Serial.println("Message arrived in topic: ");
	Serial.println(topic);
	Serial.print("Message: ");
	for(int i = 0; i < length; i++){
		Serial.print((char) payload[i]);
    receive += (char) payload[i];
	}
  Serial.println();
  Serial.println("bien moi");
  Serial.println(receive);
  Serial.println();
  Detext(receive);
}

void MQTT_Connect()
{
  //connecting to a mqtt broker 
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if(client.connect(client_id.c_str(), mqtt_username, mqtt_password)){
      Serial.println("Public emqx mqtt broker connected");
    } 
    else{
      Serial.print("failed with state ");
      Serial.print(client.state());
    }
  }
}

void Client_Loop()
{
  client.loop();
}
