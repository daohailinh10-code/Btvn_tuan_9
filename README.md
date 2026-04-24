1. Sắp xếp danh sách theo MSSV
- Tạo hàm so sánh: Dùng strcmp(a.maSV, b.maSV)
- Với mỗi sinh viên cần thêm: Tạo node mới p
- Nếu danh sách rỗng hoặc MSSV của p nhỏ hơn node đầu: Chèn p vào đầu danh sách
- Ngược lại: Gán con trỏ cur = head
- Duyệt danh sách Khi cur->next != NULL và strcmp(cur->next->maSV, p->maSV) < 0
→ dịch cur = cur->next
- Chèn p sau cur

2. In sinh viên trùng ngày sinh
- Duyệt danh sách bằng con trỏ p
- Với mỗi p: Đặt count = 0
- Duyệt danh sách lần 2 bằng con trỏ q
- Nếu ngày sinh p == q → count++
- Nếu count > 1:
- In thông tin sinh viên đó
- Nếu không có sinh viên nào thỏa:
- In: “không tìm thấy sinh viên cùng ngày sinh”

3. Xóa sinh viên trùng ngày sinh
- Duyệt danh sách bằng con trỏ p
- Với mỗi p: Đếm số sinh viên có cùng ngày sinh (giống bài 2)
- Nếu số lượng > 1: Lưu lại ngày sinh đó
- Gọi hàm xóa tất cả node có ngày sinh này:
- Nếu node đầu thỏa → xóa và cập nhật head
- Duyệt danh sách: Nếu node tiếp theo thỏa → bỏ qua node đó + free
- Sau khi xóa: Quay lại từ đầu danh sách
