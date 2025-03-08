
# Báo cáo Bài tập lớn - Nhóm 11

## 1. Thông tin nhóm
| STT | Họ và tên         | MSSV     | Vai trò    |
|-----|-------------------|----------|------------|
| 1   | Bùi Chí Tiến      | 24022837 | Thành viên |
| 2   | Đặng Thế Đạt      | 24022772 | Thành viên |
| 3   | Nguyễn Quốc Hoàn  | 24020135 | Thành viên |
| 4   | Nguyễn Thái An    | 24022761 | Nhóm Trưởng |
| 5   | Bùi Thanh Sơn     | 24022828 | Thành viên |

---

## 2. Thông tin bài tập
- **Tên bài toán**: Balo(Knapsack) có N đồ vật, khối lượng w[i] ,giá trị v[i].Tìm cách chọn sao cho không quá W,giá trị lớn nhất


---

## 3. Hướng giải quyết bài toán
### a. Phân tích bài toán
(Mô tả sơ bộ về bài toán, yêu cầu đầu vào - đầu ra, các ràng buộc nếu có)
-Bài toán Balo(knapsack) là bài tập Cho N đồ vật khác nhau, đồ vật thứ i có trọng lượng wi và giá trị vi  .Bạn mang theo một chiếc túi có tải trọng tối đa là W ,nhiệm vụ là chọn ra các đồ vật để cho vào túi sao cho tổng giá trị của các đồ vật lấy được là lớn nhất có thể.Mỗi vật chỉ có thể chọn hoặc không chọn

### b. Thuật toán/Hướng tiếp cận
(Mô tả chi tiết cách giải quyết bài toán, có thể kèm theo sơ đồ hoặc giả mã để minh họa)

- Bước 1: Xác định bài toán con
Ta sẽ dùng đệ quy để chia nhỏ bài toán lớn thành các bài toán nhỏ hơn.
Gọi dp[i][w] là giá trị lớn nhất có thể đạt được khi xét i vật phẩm đầu tiên với sức chứa tối đa w.
- CTTQ: 
-   dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w - weights[i-1]])
- 1.	Không chọn vật phẩm i → Kết quả giống như xét i-1 vật phẩm với cùng sức chứa w. 
-	  dp[i][w] = dp[i-1][w]
- 2.	Chọn vật phẩm i → Nhận thêm giá trị values[i-1] và giảm sức chứa đi weights[i-1]. 
-	  dp[i][w] = values[i-1] + dp[i-1][w - weights[i-1]]
- 3.	Lấy giá trị lớn nhất giữa hai trường hợp trên.
- Bước 2: Lưu kết quả để tránh lặp lại (Memoization)
-	  1.Dùng mảng dp để nhớ các kết quả đã tính.
-	Nếu dp[i][w] đã tính rồi thì trả về ngay thay vì tính lại.
- Bước 3: Kết quả tối ưu nhất nằm ở ô dp[n][W]
### Ưu điểm: 
- Tránh tính toạn lặp lại nhờ lưu vào bảng nhớ giúp giảm thời gian chạy so với đệ quy thuần túy.
### Nhược điểm:
- Do vẫn sử dụng đệ quy nên khi N quá lớn có thể gây tràn bộ nhớ 

---

## 4. Ví dụ minh hoạ
### Ví dụ 1
**Input:**  
4 5<br>
1 2 3 4<br>
5 5 5 5<br>
(Mô tả input) <br>Hàng 1 gồm N = 4,W = 5( số lượng của vật là 4 , Trọng lượng tối đa của balo là 5. Hàng 2 là trọng lượng của từng vật w[i] , Hàng 3 là giá trị của từng vật tương ứng v[i]

**Output:**  14
(Mô tả output)  Giá trị lớn nhất mà balo có thể mang
**Giải thích:**  
(Mô tả cách giải)<br>
Chúng ta xây dựng bảng dp[i][w], trong đó dp[i][w] biểu thị giá trị lớn nhất có thể đạt được khi xét i vật phẩm đầu tiên với sức chứa w.
|i \ w | 0  | 1  | 2  | 3  | 4  | 5 | 
|-----|---|----|---|----|----|-----  |
|0     | 0  | 0  | 0  | 0  | 0  | 0  |
|1     | 0  | 0  | 5  | 5  | 5  | 5  |
|2     | 0  | 0  | 5  | 5  |10  |10  |
|3     | 0  | 0  | 5  | 5  |10  |10  |
|4     | 0  | 5  | 5  |10  |10  |14  |

Tính toán:
Hàng 0: Không có vật phẩm nào, giá trị tối đa luôn bằng 0.
- Hàng 1 (vật phẩm có trọng lượng 2, giá trị 5):
   1. Khi w < 2: Không thể chọn vật phẩm này → giữ nguyên dp[i-1][w].
   2. Khi w >= 2: Chọn vật phẩm này → dp[i][w] = max(dp[i-1][w], 5 + dp[i-1][w-2]).
- Hàng 2 (vật phẩm có trọng lượng 3, giá trị 5):
   1. Khi w < 3: Không chọn được.
   2. Khi w >= 3: dp[i][w] = max(dp[i-1][w], 5 + dp[i-1][w-3]).
- Hàng 3 (vật phẩm có trọng lượng 4, giá trị 5):
   1. Khi w < 4: Không chọn được.
   2. Khi w >= 4: dp[i][w] = max(dp[i-1][w], 5 + dp[i-1][w-4]).
- Hàng 4 (vật phẩm có trọng lượng 1, giá trị 5):
   1. Khi w < 1: Không chọn được.
   2. Khi w >= 1: dp[i][w] = max(dp[i-1][w], 5 + dp[i-1][w-1]).

### Ví dụ 2
**Input:**  
5 10 <br>
2 2 3 3 4 <br>
3 3 4 4 5 <br>

(Mô tả input)<br> Hàng 1 gồm N = 5 ,W = 10 ( số vật là 5, Trọng lượng tối đa của balo là 10, Hàng 2 là trọng lượng của từng vật , Hàng 3 là giá trị của từng vật tương ứng 

**Output:**  14
(Mô tả output)  Giá trị lớn nhất của balo có thể mang
**Giải thích:**  
(Mô tả cách giải)<br>
Chúng ta xây dựng bảng dp[i][w], trong đó dp[i][w] biểu thị giá trị lớn nhất có thể đạt được khi xét i vật phẩm đầu tiên với sức chứa w. 

| i \ w |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  |
|-------|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
|   0   |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
|   1   |  0  |  0  |  3  |  3  |  3  |  3  |  3  |  3  |  3  |  3  |  3  |
|   2   |  0  |  0  |  3  |  3  |  6  |  6  |  6  |  6  |  6  |  6  |  6  |
|   3   |  0  |  0  |  3  |  4  |  6  |  7  |  7  | 10  | 10  | 10  | 10  |
|   4   |  0  |  0  |  3  |  4  |  6  |  7  |  8  | 10  | 11  | 14  | 14  |
|   5   |  0  |  0  |  3  |  4  |  6  |  7  |  8  | 10  | 11  | 14  | 14  |

Tính toán:
- Hàng 0: Không có vật phẩm nào, giá trị tối đa luôn bằng 0.
- Hàng 1 (vật phẩm có trọng lượng 2, giá trị 3):
  1. Khi w < 2: Không thể chọn vật phẩm này → giữ nguyên dp[i-1][w].
  2. Khi w >= 2: Chọn vật phẩm này → dp[i][w] = max(dp[i-1][w], 3 + dp[i-1][w-2]).
- Hàng 2 (vật phẩm có trọng lượng 2, giá trị 3):
  1. Khi w < 2: Không chọn được.
  2. Khi w >= 2: dp[i][w] = max(dp[i-1][w], 3 + dp[i-1][w-2]).
- Hàng 3 (vật phẩm có trọng lượng 3, giá trị 4):
  1. Khi w < 3: Không chọn được.
  2. Khi w >= 3: dp[i][w] = max(dp[i-1][w], 4 + dp[i-1][w-3]).
- Hàng 4 (vật phẩm có trọng lượng 3, giá trị 4):
  1. Khi w < 3: Không chọn được.
  2. Khi w >= 3: dp[i][w] = max(dp[i-1][w], 4 + dp[i-1][w-3]).
- Hàng 5 (vật phẩm có trọng lượng 4, giá trị 5):
  1. Khi w < 4: Không chọn được.
  2. Khi w >= 4: dp[i][w] = max(dp[i-1][w], 5 + dp[i-1][w-4]).


### Ví dụ 3
**Input:** <br>
3 2 <br>
3  4  5  <br>
11 22 33 <br>

(Mô tả input) <br>Hàng 1 N = 3, W = 2 ( số lượng vật là 3, trọng lượng tối đa của balo là 2) , Hàng 2 là trọng lượng của từng vật , Hàng 3 là giá trị của từng vật.
**Output:**  0
(Mô tả output) Giá trị lớn nhất của balo có thể mang
**Giải thích:** 
(Mô tả cách giải) xây dựng bảng tương tự 2 testcase trên.

| i \ w |  0  |  1  |  2  |
|-------|-----|-----|-----|
|   0   |  0  |  0  |  0  |
|   1   |  0  |  0  |  0  |
|   2   |  0  |  0  |  0  |
|   3   |  0  |  0  |  0  |

Tính toán 
- Hàng 0 (Không có vật phẩm nào)  
  Không thể chọn vật phẩm nào, giá trị tối đa luôn bằng 0.

- Hàng 1 (Vật phẩm 1: trọng lượng 3, giá trị 11)  
  1. Khi w < 3: Không thể chọn vật phẩm này → giữ nguyên dp[i-1][w].  
  2. Vì W = 2 < 3, nên không thể chọn vật phẩm này.

- Hàng 2 (Vật phẩm 2: trọng lượng 4, giá trị 22)  
  1. Khi w < 4: Không thể chọn vật phẩm này → giữ nguyên dp[i-1][w].  
  2. Vì W = 2 < 4, nên không thể chọn vật phẩm này.

- Hàng 3 (Vật phẩm 3: trọng lượng 5, giá trị 33)  
  1. Khi w < 5: Không thể chọn vật phẩm này → giữ nguyên dp[i-1][w]. 
---

## 5. Link video báo cáo
[Video báo cáo nhóm X](#)

---

## 6. Link source code
[Thư mục src](./src)

