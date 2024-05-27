const control_1 = document.getElementById("button_1");
const control_2 = document.getElementById("button_2");
const control_3 = document.getElementById("button_3");
const control_4 = document.getElementById("button_4");
const control_5 = document.getElementById("button_5");
const control_6 = document.getElementById("button_6");
const control_7 = document.getElementById("button_7");
const control_8 = document.getElementById("button_8");
control_1.addEventListener("click", function () {
  const confirmation = window.confirm("Xác nhận?");
  if(confirmation)
  {
    socket.emit("control_fan_living_room", "1");
  }
});

control_2.addEventListener("click", function () {
  const confirmation = window.confirm("Xác nhận?");
  if(confirmation)
  {
    socket.emit("control_light_living_room", "1");
  }
});

control_3.addEventListener("click", function () {
  const confirmation = window.confirm("Xác nhận?");
  if(confirmation)
  {
    socket.emit("control_fan_kitchen", "1");
  }
});

control_4.addEventListener("click", function () {
  const confirmation = window.confirm("Xác nhận?");
  if(confirmation)
  {
    socket.emit("control_light_kitchen", "1");
  }
});

control_5.addEventListener("click", function () {
  const confirmation = window.confirm("Xác nhận?");
  if(confirmation)
  {
    socket.emit("control_door", "1");
  }
});

control_6.addEventListener("click", function () {
  const confirmation = window.confirm("Xác nhận?");
  if(confirmation)
  {
    socket.emit("control_auto_mode_all", "1");
  }
});

control_7.addEventListener("click", function () {
  const confirmation = window.confirm("Xác nhận?");
  if(confirmation)
  {
    socket.emit("control_auto_mode_kitchen", "1");
  }
});

control_8.addEventListener("click", function () {
  const confirmation = window.confirm("Xác nhận?");
  if(confirmation)
  {
    socket.emit("control_auto_mode_living_room", "1");
  }
});


const socket = io();
var count_update_chart1 = 0, count_update_chart2 = 0;
socket.on("sensor_io_1", function (data_received) {
  let sensor_data_1 = data_received;
  document.getElementById("sensor_data_1").innerHTML = sensor_data_1;
  count_update_chart1++;
  if(count_update_chart1 == 10)
  {
    count_update_chart1 = 0;
    update_chart1.data.datasets[0].data.push(sensor_data_1);
    const maxDataPoints = 360;
    if (update_chart1.data.datasets[0].data.length > maxDataPoints) {
      update_chart1.data.datasets[0].data.shift();
    }
    const formattedTime = moment().format("HH:mm:ss, DD/MM/YYYY");
    update_chart1.data.labels.push(formattedTime);
    if (update_chart1.data.labels.length > maxDataPoints) {
      update_chart1.data.labels.shift();
    }
    update_chart1.update();
  }
});

socket.on("sensor_io_2", function (data_received) {
  let sensor_data_2 = data_received;
  document.getElementById("sensor_data_2").innerHTML = sensor_data_2;
});


socket.on("sensor_io_3", function (data_received) {
  let sensor_data_3 = data_received;
  document.getElementById("sensor_data_3").innerHTML = sensor_data_3;
  count_update_chart2++;
  if(count_update_chart2 == 10)
  {
    count_update_chart2 = 0;
    update_chart2.data.datasets[0].data.push(sensor_data_3);
    const maxDataPoints = 360;
    if (update_chart2.data.datasets[0].data.length > maxDataPoints) {
      update_chart2.data.datasets[0].data.shift();
    }
    const formattedTime = moment().format("HH:mm:ss, DD/MM/YYYY");
    update_chart2.data.labels.push(formattedTime);
    if (update_chart2.data.labels.length > maxDataPoints) {
      update_chart2.data.labels.shift();
    }
    update_chart2.update();
  }
});

socket.on("sensor_io_4", function (data_received) {
  let sensor_data_4 = data_received;
  document.getElementById("sensor_data_4").innerHTML = sensor_data_4;
});

socket.on("device_io_1", function (data_received) {
  let device_data_1 = data_received;
  document.getElementById("device_data_1").innerHTML = device_data_1;
});

socket.on("device_io_2", function (data_received) {
  let device_data_2 = data_received;
  document.getElementById("device_data_2").innerHTML = device_data_2;
});

socket.on("device_io_3", function (data_received) {
  let device_data_3 = data_received;
  document.getElementById("device_data_3").innerHTML = device_data_3;
});

socket.on("device_io_4", function (data_received) {
  let device_data_4 = data_received;
  document.getElementById("device_data_4").innerHTML = device_data_4;
});

socket.on("device_io_5", function (data_received) {
  let device_data_5 = data_received;
  document.getElementById("device_data_5").innerHTML = device_data_5;
});

socket.on("device_io_6", function (data_received) {
  let device_data_6 = data_received;
  document.getElementById("device_data_6").innerHTML = device_data_6;
});

socket.on("device_io_7", function (data_received) {
  let device_data_7 = data_received;
  document.getElementById("device_data_7").innerHTML = device_data_7;
});

socket.on("device_io_8", function (data_received) {
  let device_data_8 = data_received;
  document.getElementById("device_data_8").innerHTML = device_data_8;
});

const update_chart1 = new Chart("sensorChart1", {
  type: "line",
  data: {
    labels: [],
    datasets: [
      {
        label: "Nhiệt độ",
        lineTension: 0.3,
        backgroundColor: "#AAff7f",
        borderColor: "#AAff7f",
        data: [],
      },
    ],
  },
  options: {
    responsive: true,
    interaction: {
      mode: "index",
      intersect: false,
    },
    scales: {
      x: {
        title: {
          display: true,
          text: "Thời gian",
        },
      },
      y: {
        title: {
          display: true,
          text: "Giá trị nhiệt độ(C)",
        },
      },
    },
  },
});

const update_chart2 = new Chart("sensorChart2", {
  type: "line",
  data: {
    labels: [],
    datasets: [
      {
        label: "Khí gas",
        lineTension: 0.3,
        backgroundColor: "#7FAAFF",
        borderColor: "#7FAAFF",
        data: [],
      },
    ],
  },
  options: {
    responsive: true,
    interaction: {
      mode: "index",
      intersect: false,
    },
    scales: {
      x: {
        title: {
          display: true,
          text: "Thời gian",
        },
      },
      y: {
        title: {
          display: true,
          text: "Giá trị khí gas(%)",
        },
      },
    },
  },
});