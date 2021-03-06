#include "pch.h"
#include "..\laba 2\Verzera.h"
#include "..\laba 2\Verzera.cpp"

TEST(VerzeraConstructor, DefaultConstructor){
    Prog2::Verzera a1;
    ASSERT_EQ(0, a1.getA().x);
    ASSERT_EQ(0, a1.getA().y);
}

TEST(VerzeraConstructor, InitConstructors){
    Prog2::Verzera a2(3);
    Prog2::Point p(0, 3);
    ASSERT_EQ(3, a2.getA().y);
    ASSERT_EQ(0, a2.getA().x);
    Prog2::Verzera a4(2, 0);
    ASSERT_EQ(2, a4.getA().y);
    ASSERT_EQ(0, a4.getA().x);
}
TEST(VerzeraConstructor, TestException){
    ASSERT_ANY_THROW(Prog2::Verzera(2, 5));
}
TEST(VerzeraGetSet, Setters){
    Prog2::Verzera a;
    Prog2::Point p1(0, 2);
    a.setA(p1);
    ASSERT_EQ(0, a.getA().x);
    ASSERT_EQ(2, a.getA().y);
    Prog2::Point p2(-3, 2);
    ASSERT_ANY_THROW(a.setA(p2));
}
TEST(Verzera, Area) {
    Prog2::Verzera a1(10, 0);
    const double PI = 3.14159, err = 0.00001;
    ASSERT_NEAR(PI * 100, a1.Area(), err);
    Prog2::Verzera a2;
    ASSERT_NEAR(0, a2.Area(), err);
}
TEST(Verzera, CoordY) {
    Prog2::Verzera a1(10, 0);
    ASSERT_EQ(10, a1.CoordY(0));
    Prog2::Verzera a2;
    ASSERT_EQ(0, a2.CoordY(20));
    ASSERT_ANY_THROW(a2.CoordY(0));
}
TEST(Verzera, FRM) {
    Prog2::Verzera a1(10, 0);
    ASSERT_STREQ("y = 1000/( 100 + x^2 )", a1.frm().c_str());
    Prog2::Verzera a2;
    ASSERT_STREQ("y = 0; {x!=0}", a2.frm().c_str());
}
TEST(Verzera, Inflection) {
    const double err = 0.00001;
    Prog2::Verzera a1(10, 0);
    Prog2::Point p1, p2;
    Prog2::Point p3(5.77350, 7.5), p4(-5.77350, 7.5);
    a1.Inflection(p1, p2);
    ASSERT_NEAR(p3.x, p1.x, err);
    ASSERT_NEAR(p3.y, p1.y, err);
    ASSERT_NEAR(p4.y, p2.y, err);
    ASSERT_NEAR(p4.x, p2.x, err);
    Prog2::Verzera a2;
    const Prog2::Point p5(0, 0);
    a2.Inflection(p1, p2);
    ASSERT_NEAR(p5.x, p1.x, err);
    ASSERT_NEAR(p5.y, p1.y, err);
    ASSERT_NEAR(p5.y, p2.y, err);
    ASSERT_NEAR(p5.x, p2.x, err);
}

TEST(Verzera, Volume) {
    const double err = 0.00001;
    Prog2::Verzera a1(10, 0);
    ASSERT_NEAR(4934.79386, a1.Volume(), err);
    Prog2::Verzera a2;
    ASSERT_NEAR(0, a2.Volume(), err);
}
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}