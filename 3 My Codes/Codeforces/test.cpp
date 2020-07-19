#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood, Board, Steel};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;

public:
    Furniture(double p, double d, Material m) : price(0), discount(0), madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val > 0)
            price = val;
    }
    void setDiscount(double val)
    {
        if(val <= price)
            discount = val;
    }
    void setMadeof(Material val)
    {
        madeof = val;
    }
    string getMadeof()
    {
        if(madeof == Material::Wood)
            return string("Wood");
        else if(madeof == Material::Board)
            return string("Board");
        else if(madeof == Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails() = 0;
};

enum class BedSize {Single,SemiDouble,Double};
class Bed: public Furniture
{
protected:
    BedSize bs;
public:
    Bed(double p = 0, double d = 0, Material m = Material::Wood, BedSize b = BedSize::Single) : Furniture (p, d, m)
    {
        bs = b;
    }
    void productDetails()
    {
        cout << "-------------------------\n";
        cout << "Regular Price: " << price << "\n";
        cout << "Discounted Price: " << price - discount << "\n";
        cout << "Material: " << getMadeof() << "\n";
        cout << "Bed Size: " << getSize() << "\n";
        cout << "#########################\n";
    }

    string getSize()
    {
        switch (bs)
        {
        case BedSize::Single:
            return "Single";
        case BedSize::SemiDouble:
            return "SemiDouble";
        case BedSize::Double:
            return "Double";
        }
    }
};

//enum class SeatNumer{One, Two, Three, Four, Five};
//class Sofa: public Furniture
//{
//    SeatNumer sn;
//    Sofa(SeatNumer s)
//    {
//        sn = s;
//    }
//};
//
//enum classs ChairCount{Two, Four, Six};
//class DiningTable: public Furniture
//{
//    ChairCount cc;
//    DiningTable(ChairCount c)
//    {
//        cc = c;
//    }
//};

int main()
{
    Bed mybed(0, 0, Material::Steel, BedSize::SemiDouble);
    mybed.productDetails();
}
