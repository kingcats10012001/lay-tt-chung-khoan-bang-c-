#ifndef FIND_H
#define FIND_H

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

string getMiddleString(const string& input, const string& begin, const string& end, int start_pos = 0) {
    string result = "";
    //tìm vị trí của string begin trong string input
    // Ví Dụ : 
    // Tìm abc trong chuỗi xyzabcxxx sẽ trả về kết quả là 3 là vị trí bắt đầu của chuỗi abc trong chuỗi xyzabcxxx
    // vị trí đấy đc gán cho biến start_pos

    start_pos = input.find(begin, start_pos);
    // start_pos + thêm độ dài của string begin để ra vị trí bắt đầu cần lấy
    // ví dụ lấy chuỗi giữa 123 và abc trong chuỗi 123xyzabc thì sau khi tìm đc vị trí 123 là 0 thì cần + thêm độ dài của 123 là 3 để ra vị trí bắt đầu của chuỗi cần tìm là 3 (vị trí của chữ x) 

    start_pos += begin.length();
    // tìm vị trí của chuỗi kết thúc như trong ví dụ trên (123xyzabc) là vị trí của abc và là 66

    int end_pos = input.find(end, start_pos);

    if (end_pos <= start_pos) return "";
    //lấy ra chuỗi con từ chuỗi input có vị trí bắt đầu là start_pos và có độ dài là vị trí của abc trừ đi start_pos kết quả là 3 

    result = input.substr(start_pos, end_pos - start_pos);
    return result;
};

// Lấy dòng thứ {line_number} từ string input
string getLine(const string& input, int line_number) {
    int count = 0;
    int begin_pos = 0;
    int end_pos = 0;
    string result = "";
    if (line_number == 0) return "Invalid";
    while (count < line_number - 1){
        begin_pos = input.find("\n", begin_pos);
        if (begin_pos ==  string::npos) return "Invalid";
        count++;
        begin_pos++;
    };
    end_pos = input.find("\n",begin_pos);
    if (end_pos == string::npos) return "Invalid"; 
    else 
        result = input.substr(begin_pos, end_pos - begin_pos);
    return result;
};

// Lấy chuỗi chứa tất cả thông tin cần thiết của mã chứng khoán
// chuỗi được chia làm nhiều dòng tương ứng với các thông tin
string* getInfo(const string& input, int amount) {
    string* info = new string[amount];
    string begin = "<tr onmouseover=\"hoverTR(this)\" onmouseout=\"outTR(this)\">\n";
    string end = "\t</tr>\n";
    int pos = 0;
    //amount là số lượng info cần lấy ở đây là 20
    for (int i = 0; i < amount; i++) {
        int end_pos;
         // tìm vị trí của string begin với vị trí bắt đầu tìm là pos
        pos = input.find(begin,pos);
        // nếu tìm thấy thì tìm tiếp vị trí của string end với vị trí bắt đầu là pos (ở đây pos đã đc gán cho vị trí mới là vị trí bắt đầu của string begin)
        if (pos != string::npos) {
            end_pos = input.find(end,pos);
        } else break;
        // lấy ra cái string info từ input
        info[i] = input.substr(pos + begin.length(), end_pos - pos - begin.length());
         // để lần lấy tiếp theo ko bị lặp lại (lấy đi lấy lại phần tử ban đầu thì cần tăng biến pos là vị trí bắt đầu tìm phần tử begin thêm 1 khoảng = độ dài của string info)
        pos+=info[i].length();
         // + thêm \n để tiện cho hàm getLine nhỡ nó ko có xuống dòng ở cuối cùngcùng
        info[i]+="\n";
    };
    return info;
};

// cấu trúc của 1 mã chứng khoán bao gồm tên công ty, mã, số thứ tự, giá sàn, giá trần, giá đóng cửa, khối lượng
struct Company {
    string name = "Invalid";
    string code = "Invalid";
    int stt = -1;
    double price_ceiling = -1;
    double price_floor = -1;
    string price_close = "-1";
    string mass = "-1";
    
    Company(){};
    Company(const string& info) {
        // stt              line 1
        string line = getLine(info, 1);
        this->stt = stoi(getMiddleString(line, ">", "</td>"));

        // code             line 2
        line = getLine(info, 2);
        this->name = getMiddleString(line, "title=\"", "\"");
        this->code = getMiddleString(line, "<strong>", "</strong>");

        // price ceiling    line 3
        line = getLine(info, 3);
        this->price_ceiling = stod(getMiddleString(line, "<span class=\"price_ceiling\">", "</span>"));

        // price floor      line 4
        line = getLine(info, 4);
        this->price_floor = stod(getMiddleString(line, "<span class=\"price_floor\">", "</span>"));

        //price_close       line 6
        line = getLine(info, 6);
        this->price_close = getMiddleString(line, ">", "</span>", line.find("span"));

        // mass             line 10
        line = getLine(info, 10);
        this->mass = getMiddleString(line, "<td align=\"right\" class=\"td_bottom3 td_bg3\">", "</td>");
    }
};

#endif 