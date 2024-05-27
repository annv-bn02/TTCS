const express = require("express");
const app = express();
const ejs = require("ejs");
const mqtt = require("mqtt");
//const mysql = require("mysql");

var port = 3000;

/*var con = mysql.createConnection({
  host: "localhost",
  user: "root",
  password: "",
  database: "abc",
});

con.connect(function (err) {
  if (err) throw err;
});*/

app.set("view engine", "ejs");
app.get("/", function (req, res) {
  res.render("index");
});
app.use("/public", express.static("public"));

var server = require("http").Server(app);
var io = require("socket.io")(server);
server.listen(port);

const options = {
  username: "artnguyen",
  password: "admin",
  rejectUnauthorized: false,
};

const client = mqtt.connect(
  "mqtt://broker.emqx.io:1883",
  options
);

client.on("connect", function () {
  console.log("Da khoi chay server.");
  // client.subscribe("Broke_send");
  client.subscribe("Esp32toBroke");
});

client.on("message", function (topic, message) {
  const data = JSON.parse(message);
  var sensor_data_1 = parseFloat(data.temp).toFixed(2);
  var sensor_data_2 = parseInt(data.light);
  var sensor_data_3 = parseFloat(data.gas).toFixed(2);
  var sensor_data_4 = parseInt(data.prox);
  var device_data_1 = parseInt(data.fan_living_room);
  var device_data_2 = parseInt(data.light_living_room);
  var device_data_3 = parseInt(data.fan_kitchen);
  var device_data_4 = parseInt(data.light_kitchen);
  var device_data_5 = parseInt(data.door);
  var device_data_6 = parseInt(data.auto_mode_all);
  var device_data_7 = parseInt(data.auto_mode_kitchen);
  var device_data_8 = parseInt(data.auto_mode_living_room);
  io.emit("sensor_io_1", sensor_data_1);
  io.emit("sensor_io_2", sensor_data_2 ? "Tối" : "Sáng");
  io.emit("sensor_io_3", sensor_data_3);
  io.emit("sensor_io_4", sensor_data_4 ? "Không" : "Có");
  // // Kiểm tra và điều khiển thiết bị dựa trên giá trị của device_data
  io.emit("device_io_1", device_data_1 ? "Bật" : "Tắt");
  io.emit("device_io_2", device_data_2 ? "Bật" : "Tắt");
  io.emit("device_io_3", device_data_3 ? "Bật" : "Tắt");
  io.emit("device_io_4", device_data_4 ? "Bật" : "Tắt");
  io.emit("device_io_5", device_data_5 ? "Mở" : "Đóng");
  io.emit("device_io_6", device_data_6 ? "Bật" : "Tắt");
  io.emit("device_io_7", device_data_7 ? "Bật" : "Tắt");
  io.emit("device_io_8", device_data_8 ? "Bật" : "Tắt");
});


io.on("connection", function (socket) {
  socket.on("control_fan_living_room", function (state) {
    client.publish("fan_living_room", state);
    const data = {
      fan_living_room: 1, // Thay thế bằng dữ liệu bạn muốn gửi
    };
    client.publish('WebtoBroke', JSON.stringify(data));
  });
});

io.on("connection", function (socket) {
  socket.on("control_light_living_room", function (state) {
    client.publish("light_living_room", state);
    const data = {
      light_living_room: 1, // Thay thế bằng dữ liệu bạn muốn gửi
    };
    client.publish('WebtoBroke', JSON.stringify(data));
  });
});

io.on("connection", function (socket) {
  socket.on("control_fan_kitchen", function (state) {
    client.publish("fan_kitchen", state);
    const data = {
      fan_kitchen: 1, // Thay thế bằng dữ liệu bạn muốn gửi
    };
    client.publish('WebtoBroke', JSON.stringify(data));
  });
});

io.on("connection", function (socket) {
  socket.on("control_light_kitchen", function (state) {
    client.publish("light_kitchen", state);
    const data = {
      light_kitchen: 1, // Thay thế bằng dữ liệu bạn muốn gửi
    };
    client.publish('WebtoBroke', JSON.stringify(data));
  });
});

io.on("connection", function (socket) {
  socket.on("control_door", function (state) {
    client.publish("door", state);
    const data = {
      door: 1, // Thay thế bằng dữ liệu bạn muốn gửi
    };
    client.publish('WebtoBroke', JSON.stringify(data));
  });
});

io.on("connection", function (socket) {
  socket.on("control_auto_mode_all", function (state) {
    client.publish("auto_mode_all", state);
    const data = {
      auto_mode_all: 1, // Thay thế bằng dữ liệu bạn muốn gửi
    };
    client.publish('WebtoBroke', JSON.stringify(data));
  });
});

io.on("connection", function (socket) {
  socket.on("control_auto_mode_kitchen", function (state) {
    client.publish("auto_mode_kitchen", state);
    const data = {
      auto_mode_kitchen: 1, // Thay thế bằng dữ liệu bạn muốn gửi
    };
    client.publish('WebtoBroke', JSON.stringify(data));
  });
});

io.on("connection", function (socket) {
  socket.on("control_auto_mode_living_room", function (state) {
    client.publish("auto_mode_living_room", state);
    const data = {
      auto_mode_living_room: 1, // Thay thế bằng dữ liệu bạn muốn gửi
    };
    client.publish('WebtoBroke', JSON.stringify(data));
  });
});
