#include <iostream>
#include <cstring>

using namespace std;

// Định nghĩa các struct như trong mã đã cung cấp

struct Ngay {
    int ngay, thang, nam;
};

struct SinhVien {
    char maSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};

struct Node {
    SinhVien data;
    Node *link;
};

struct ListSV {
    Node *first;
    Node *last;
};

// Các hàm được định nghĩa trước (taodanhsach, sosanhmaSV, them_SV, in_SV, check_ngay, xoa_SV) 

void taodanhsach(ListSV *list);
bool sosanhmaSV(const char *ma1, const char *ma2);
void them_SV(ListSV *list, SinhVien *sv);
void in_SV(const ListSV *list);
bool check_ngay(const Ngay &d1, const Ngay &d2);
void xoa_SV(ListSV *list);

void nhapSinhVien(SinhVien &sv) {
    cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;
    cout << "Nhap ho ten sinh vien: ";
    cin.ignore();
    cin.getline(sv.hoTen, 50);
    cout << "Nhap gioi tinh (0 - Nam, 1 - Nu): ";
    cin >> sv.gioiTinh;
    cout << "Nhap ngay sinh (ngay thang nam): ";
    cin >> sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;
    cout << "Nhap dia chi: ";
    cin.ignore();
    cin.getline(sv.diaChi, 100);
    cout << "Nhap lop: ";
    cin >> sv.lop;
    cout << "Nhap khoa: ";
    cin >> sv.khoa;
}

void ListSV_sameNgay(ListSV *list) {
    Node *p = list->first;
    bool found = false;
    while (p != NULL) {
        Node *q = p->link;
        while (q != NULL) {
            if (check_ngay(p->data.ngaySinh, q->data.ngaySinh)) {
                found = true;
                cout << "Ma SV: " << p->data.maSV << ", Ho Ten: " << p->data.hoTen << ", Ngay sinh: " << p->data.ngaySinh.ngay << "/" << p->data.ngaySinh.thang << "/" << p->data.ngaySinh.nam << endl;
                cout << "Ma SV: " << q->data.maSV << ", Ho Ten: " << q->data.hoTen << ", Ngay sinh: " << q->data.ngaySinh.ngay << "/" << q->data.ngaySinh.thang << "/" << q->data.ngaySinh.nam << endl;
            }
            q = q->link;
        }
        p = p->link;
    }
    if (!found) {
        cout << "Khong tim thay sinh vien cung ngay sinh" << endl;
    }
}

int main() {
    ListSV list;
    taodanhsach(&list);
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        SinhVien sv;
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        nhapSinhVien(sv);
        them_SV(&list, &sv);
    }

    cout << "\nDanh sach sinh vien:\n";
    in_SV(&list);

    cout << "\nDanh sach sinh vien co cung ngay sinh:\n";
    ListSV_sameNgay(&list);

    cout << "\nDanh sach sinh vien sau khi xoa sinh vien co cung ngay sinh:\n";
    xoa_SV(&list);
    in_SV(&list);

    return 0;
}
