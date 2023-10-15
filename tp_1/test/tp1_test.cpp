// Entetes //---------------------------------------------------------------------------------------
#include "catch.hpp"

#include <sstream>
#include <typeinfo>

#include <Cartesian.hpp>
#include <Polar.hpp>
//#include <nuage.hpp>

// Tests //-----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------ 1
TEST_CASE ( "TP1_Polaire::Constructeur" ) {
 const double a = 12.0;
 const double d = 24.0;

 Polar p(a,d);

 REQUIRE ( p.getAngle() == Approx(a) );
 REQUIRE ( p.getDistance() == Approx(d) );
}

//------------------------------------------------------------------------------------------------ 2
TEST_CASE ( "TP1_Polaire::ConstructeurDefaut" ) {
 Polar p;

 REQUIRE ( p.getAngle() == Approx(0.0) );
 REQUIRE ( p.getDistance() == Approx(0.0) );
}

//------------------------------------------------------------------------------------------------ 3
TEST_CASE ( "TP1_Polaire::Accesseurs" ) {
 const double a = 12.0;
 const double d = 24.0;

 Polar p(13.0,25.0);

 p.setAngle(a);
 p.setDistance(d);

 REQUIRE ( p.getAngle() == Approx(a) );
 REQUIRE ( p.getDistance() == Approx(d) );
}

//------------------------------------------------------------------------------------------------ 4
TEST_CASE ( "TP1_Polaire::AccesseursConstants" ) {
 const Polar p;

 REQUIRE ( p.getAngle() == Approx(0.0) );
 REQUIRE ( p.getDistance() == Approx(0.0) );
}

//------------------------------------------------------------------------------------------------ 5
TEST_CASE ( "TP1_Polaire::Affichage" ) {
 Polar p(12.0,24.0);
 std::stringstream flux;

 p.display(flux);

 REQUIRE ( flux.str() == "(a=12;d=24)" );
}

//------------------------------------------------------------------------------------------------ 6
TEST_CASE ( "TP1_Cartesien::Constructeur" ) {
 const double x = 12.0;
 const double y = 24.0;

 Cartesian c(x,y);

 REQUIRE ( c.getX() == Approx(x) );
 REQUIRE ( c.getY() == Approx(y) );
}

//------------------------------------------------------------------------------------------------ 7
TEST_CASE ( "TP1_Cartesien::ConstructeurDefaut" ) {
 Cartesian c;

 REQUIRE ( c.getX() == Approx(0.0) );
 REQUIRE ( c.getY() == Approx(0.0) );
}

//------------------------------------------------------------------------------------------------ 8
TEST_CASE ( "TP1_Cartesien::Accesseurs" ) {
 const double x = 12.0;
 const double y = 24.0;

 Cartesian c(13.0,25.0);

 c.setX(x);
 c.setY(y);

 REQUIRE ( c.getX() == Approx(x) );
 REQUIRE ( c.getY() == Approx(y) );
}

//------------------------------------------------------------------------------------------------ 9
TEST_CASE ( "TP1_Cartesien::AccesseursConstants" ) {
 const Cartesian c;

 REQUIRE ( c.getX() == Approx(0.0) );
 REQUIRE ( c.getY() == Approx(0.0) );
}

//----------------------------------------------------------------------------------------------- 10
TEST_CASE ( "TP1_Cartesien::Affichage" ) {
 Cartesian c(12.0,24.0);
 std::stringstream flux;

 c.display(flux);

 REQUIRE ( flux.str() == "(x=12;y=24)" );
}

//----------------------------------------------------------------------------------------------- 11
TEST_CASE ( "TP1_Point::AffichageVirtuel" ) {
 Polar p(12.0,24.0);
 Cartesian c(13.0,25.0);

 const Point & p1 = p;
 const Point & p2 = c;

 std::stringstream flux1;
 std::stringstream flux2;

 p1.display(flux1);
 p2.display(flux2);

 REQUIRE ( flux1.str() == "(a=12;d=24)" );
 REQUIRE ( flux2.str() == "(x=13;y=25)" );
}

//----------------------------------------------------------------------------------------------- 12
TEST_CASE ( "TP1_Point::OperateurFlux" ) {
 Polar p(12.0,24.0);
 Cartesian c(13.0,25.0);

 const Point & p1 = p;
 const Point & p2 = c;

 std::stringstream flux1;
 std::stringstream flux2;

 flux1 << p1;
 flux2 << p2;

 REQUIRE ( flux1.str() == "(a=12;d=24)" );
 REQUIRE ( flux2.str() == "(x=13;y=25)" );
}

//----------------------------------------------------------------------------------------------- 13
TEST_CASE ( "TP1_Point::ConversionVersPolaire_V1" ) {
 const double x = 12.0;
 const double y = 24.0;
 const double a = 63.434948;
 const double d = 26.832815;

 const Cartesian c(x,y);
 Polar p;

 c.convert(p);

 REQUIRE ( p.getAngle() == Approx(a).epsilon(1e-3) );
 REQUIRE ( p.getDistance() == Approx(d).epsilon(1e-3) );
}

//----------------------------------------------------------------------------------------------- 14
TEST_CASE ( "TP1_Point::ConversionVersCartesien_V1" ) {
 const double a = 12.0;
 const double d = 24.0;
 const double x = 23.475542;
 const double y = 4.9898805;

 const Polar p(a,d);
 Cartesian c;

 p.convert(c);

 REQUIRE ( c.getX() == Approx(x).epsilon(1e-3) );
 REQUIRE ( c.getY() == Approx(y).epsilon(1e-3) );
}

//----------------------------------------------------------------------------------------------- 15
TEST_CASE ( "TP1_Point::ConversionVirtuel" ) {
 const double x = 12.0;
 const double y = 24.0;
 const double a = 63.434948;
 const double d = 26.832815;

 Cartesian c(x,y);
 Polar p(a,d);

 const Point * x1 = &c;
 const Point * x2 = &p;

 Cartesian c1;
 Cartesian c2;
 Polar p1;
 Polar p2;

 x1->convert(c1);
 x1->convert(p1);
 x2->convert(c2);
 x2->convert(p2);

 REQUIRE ( c1.getX() == Approx(x).epsilon(1e-3) );
 REQUIRE ( c1.getY() == Approx(y).epsilon(1e-3) );
 REQUIRE ( c2.getX() == Approx(x).epsilon(1e-3) );
 REQUIRE ( c2.getY() == Approx(y).epsilon(1e-3) );

 REQUIRE ( p1.getAngle() == Approx(a).epsilon(1e-3) );
 REQUIRE ( p1.getDistance() == Approx(d).epsilon(1e-3) );
 REQUIRE ( p2.getAngle() == Approx(a).epsilon(1e-3) );
 REQUIRE ( p2.getDistance() == Approx(d).epsilon(1e-3) );
}

//----------------------------------------------------------------------------------------------- 16
TEST_CASE ( "TP1_Point::ConversionVersPolaire_V2" ) {
 const double x = 12.0;
 const double y = 24.0;
 const double a = 63.434948;
 const double d = 26.832815;

 Cartesian c(x,y);
 Polar p(c);

 REQUIRE ( p.getAngle() == Approx(a).epsilon(1e-3) );
 REQUIRE ( p.getDistance() == Approx(d).epsilon(1e-3) );
}

//----------------------------------------------------------------------------------------------- 17
TEST_CASE ( "TP1_Point::ConversionVersCartesien_V2" ) {
 const double a = 12.0;
 const double d = 24.0;
 const double x = 23.475542;
 const double y = 4.9898805;

 Polar p(a,d);
 Cartesian c(p);

 REQUIRE ( c.getX() == Approx(x).epsilon(1e-3) );
 REQUIRE ( c.getY() == Approx(y).epsilon(1e-3) );
}

//----------------------------------------------------------------------------------------------- 18
/*TEST_CASE ( "TP1_Nuage::Ajout" ) {
 Cartesian p1(12.0,24.0);
 Polar p2(13.0,25.0);
 Polar p3(p1);
 Cartesian p4(p2);

 Nuage n;

 REQUIRE ( n.size() == 0u );

 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 REQUIRE ( n.size() == 4u );
}*/

//----------------------------------------------------------------------------------------------- 19
/*TEST_CASE ( "TP1_Nuage::Iterateurs" ) {
 Cartesian p1(12.0,24.0);
 Polar p2(13.0,25.0);
 Polar p3(p1);
 Cartesian p4(p2);

 Nuage n;

 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Point * t[4];
 unsigned i = 0;
 Nuage::const_iterator it = n.begin();

 while (it!=n.end()) t[i++]=*(it++);

 REQUIRE ( typeid(*(t[0])) == typeid(Cartesian) );
 REQUIRE ( typeid(*(t[1])) == typeid(Polar) );
 REQUIRE ( typeid(*(t[2])) == typeid(Polar) );
 REQUIRE ( typeid(*(t[3])) == typeid(Cartesian) );

 Cartesian & p5 = *static_cast<Cartesian *>(t[0]);
 Polar & p6 = *static_cast<Polar *>(t[1]);
 Polar & p7 = *static_cast<Polar *>(t[2]);
 Cartesian & p8 = *static_cast<Cartesian *>(t[3]);

 REQUIRE ( p5.getX() == Approx(12.0) );
 REQUIRE ( p5.getY() == Approx(24.0) );
 REQUIRE ( p6.getAngle() == Approx(13.0) );
 REQUIRE ( p6.getDistance() == Approx(25.0) );

 REQUIRE ( p7.getAngle() == Approx(63.434948).epsilon(1e-3) );
 REQUIRE ( p7.getDistance() == Approx(26.832815).epsilon(1e-3) );
 REQUIRE ( p8.getX() == Approx(24.359251).epsilon(1e-3) );
 REQUIRE ( p8.getY() == Approx(5.623776).epsilon(1e-3) );
}*/

//--------------------------------------------------------------------------------------Commun 20-22
/*double x[] = { 3,7,13,27 };
double y[] = { 4,8,16,32 };

Cartesian p1(x[0],y[0]);
Cartesian p2(x[1],y[1]);
Cartesian p3(x[2],y[2]);
Cartesian p4(x[3],y[3]);

Nuage n;*/

//----------------------------------------------------------------------------------------------- 20
/*TEST_CASE ( "TP1_Nuage::Barycentre" ) {
 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Cartesian b = barycentre(n);

 REQUIRE ( b.getX() == Approx((x[0]+x[1]+x[2]+x[3])/4) );
 REQUIRE ( b.getY() == Approx((y[0]+y[1]+y[2]+y[3])/4) );
}*/

//----------------------------------------------------------------------------------------------- 21
/*TEST_CASE ( "TP1_Nuage::BarycentreCartesien" ) {
 Cartesian b = BarycentreCartesien()(n);

 REQUIRE ( b.getX() == Approx((x[0]+x[1]+x[2]+x[3])/4) );
 REQUIRE ( b.getY() == Approx((y[0]+y[1]+y[2]+y[3])/4) );
}*/

//----------------------------------------------------------------------------------------------- 22
/*TEST_CASE ( "TP1_Nuage::BarycentrePolaire" ) {
 Polar p(Cartesian((x[0]+x[1]+x[2]+x[3])/4,(y[0]+y[1]+y[2]+y[3])/4));
 Polar b = BarycentrePolaire()(n);

 REQUIRE ( b.getAngle() == Approx(p.getAngle()) );
 REQUIRE ( b.getDistance() == Approx(p.getDistance()) );
}*/

// Fin //-------------------------------------------------------------------------------------------
