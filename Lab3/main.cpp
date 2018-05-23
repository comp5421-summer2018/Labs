#include <iostream>
#include<fstream>

using namespace std;

class Time
{
public:
    // default constructor:
    // No parameters or all parameters are defaulted

    // Default constructor with all default parameters
//    Time(unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0){
//        setTime(hour, minute, second);
//    }


    // C++11 has constructor delegation
    // Limitation: Cannot initialize any other members when doing delegation
    // https://stackoverflow.com/questions/7349183/constructor-chaining-in-c/33275207#33275207
    Time() : Time{1} {
    }

    // Alternative syntax for constructor delegation
    //    Time() : Time(1){
    //    }


    explicit Time(int t){
        setTime(t, t, t);
    }

    void setTime(unsigned int hour, unsigned int minute, unsigned int second){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

private:
    unsigned int hour{0};
    unsigned int minute{0};
    unsigned int second{0};
};


/**
 * Example with copy constructor
 */
class Point
{
private:
    int x, y;
public:
    Point(int x1, int y1) { x = x1; y = y1; }

    // Copy constructor
    Point(const Point &p2) {x = p2.x; y = p2.y; }

    int getX()		 { return x; }
    int getY()		 { return y; }
};

class Rectangle{

private:
    int length;
    int width;
public:
    Rectangle(){
        length=0;
        width=0;
    }

    Rectangle(int l, int w){
        length=l;
        width=w;
    }

    void operator = (const Rectangle &R ) {

        length=R.length;

        width=R.width;
    }

    void displayRectangle() {

        cout<<"length: "<<length<<" width: "<<width<<endl;
    }

};


// Extraction (>>) and insertion (<<) operators
class Date{

public:
    Date(int d,int m,int y)
    {
        day=d;

        month=m;

        year=y;
    }


    int day;
    int month;
    int year;

};

istream &operator>>(istream &input, Date &D)
{
    int d,m,y;

    input>>d;
    input>>m;
    input>>y;

    D=Date(d,m,y);

    return input;

}

ostream &operator<<(ostream &output, const Date &D)
{
    return output<<"Date is "<<D.day<<"/"<<D.month<<"/"<<D.year<<endl;
}


int main()
{
    std::cout << "Hello, World!" << std::endl;

    // Use explicit on 1 param constructor to prevent automatic convertion
    // Time t = 2;
    Time t = Time();

    // Copy constructor
    // ------------------------------------------

    Point p1(10, 15); // Normal constructor is called here
    Point p2 = p1; // Copy constructor is called here

    // Let us access values assigned by constructors
    cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
    cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();


    // = Operator overload
    // ------------------------------------------
    Rectangle r1(10,7), r2(12,9);

    cout<<"First Rectangle: ";
    r1.displayRectangle();

    cout<<"Second Rectangle: ";
    r2.displayRectangle();

    r1=r2;

    cout<<"First Rectangle: ";
    r1.displayRectangle();

    // Read from file
    // ------------------------------------------

    ifstream in;

    in.open("../numbers.txt");

    int x;

    while(!in.eof())
    {
        in>>x;

        cout<<x<<" "<<endl;

    }

    in.close();

    // Write to a file
    // ------------------------------------------
    ofstream out;

    out.open("sample.txt");

    out<<"name "<<"Smith"<<endl;
    out<<"name "<<"Nancy"<<endl;

    out.close();

    // Overload extraction and insertion operators
    // ------------------------------------------
    Date ob(2,4,1980);

    cout << "Enter date in format month<enter>day<enter>year<enter>" << endl;
    cin>>ob;
    cout<<ob;

    return 0;
}