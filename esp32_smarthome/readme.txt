SSID: "esp32_smarthome"
pass: "12345678"

Cảm biến
- Gas: 36
- Ánh sáng: 25
- Nhiệt độ: 39
- Tiệm cận: 2

Nút nhấn
chuyển sang auto: 35
đk quạt phòng khách: 26
đk đèn phòng khách: 32
dk quạt bếp: 33
đk đèn bếp: 34

servo: 12
đèn cửa: 27
còi cảnh báo: 14
chân SS rfid: 5
chân RST rfid: 0
quạt p khách: 15
đèn p khách: 4
quạt bếp: 16
đèn bếp: 17

Tính năng:
- Kết nối wifi, mặc định là chế độ auto
- Auto là trời tối bật 2 đèn trong nhà, nhiệt độ trên 30 độ bật quạt phòng khách, nồng độ khí gas trên 20% bật quạt bếp, dưới 5% thì tắt bếp.
- Bấm 1 trong 4 nút đk thiết bị, chế độ chuyển sang manual
- Bấm nút 35, chuyển sang chế độ auto
- điều khiển thiết bị thông qua mqtt
