1. Nhập vào Danh sách sinh viên và in ra theo thứ tự tăng dần của MSSV:
   - Sử dụng hàm strcmp so sánh 2 MSSV;
   -   Tạo hàm so sánh
   -   Cho con trỏ p truy cập vào dữ liệu danh sách đã tạo
   -   Nếu phần tử đầu khác Null, gán giá trị tiếp theo với giá trị đầu
   -   Con trỏ cur được gán với con trỏ head
   -   Di chuyển con trỏ cur đến vị tiếp theo gán với con trỏ p
2. In ra những sinh viên có cùng ngày sinh
   - Tạo con trỏ p duyệt mảng
   - Sử dụng hàm strcmp để so sánh ngày sinh
   - giống nhau=> count++, dịch chuyển con trỏ p
   - Gía trị count khác 0=> in ra, dịch chuyển con trỏ p
   - nếu không tìm thấy => in ra "khong tim thay sinh vien cung ngay sinh"
3. Xóa những sinh viên có cùng ngày sinh ra khỏi danh sách
- Tương tự như việc in ra những sinh viên có cùng ngày sinh khác bước cuối là giải phóng phần tử thỏa mãn điều kiện
- 
