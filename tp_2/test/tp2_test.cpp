// Entetes //---------------------------------------------------------------------------------------
#include "catch.hpp"

#include <cmath>

#include <Nuage.hpp>

// Tests //-----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------ 1
TEST_CASE ( "TP2_Nuage::Ajout" ) {
 Nuage<Cartesian> n;

 REQUIRE ( n.size() == 0u );

 n.ajouter(Cartesian(12,34));
 n.ajouter(Cartesian(56,78));
 n.ajouter(Cartesian(90,12));
 n.ajouter(Cartesian(34,56));

 REQUIRE ( n.size() == 4u );
}

//------------------------------------------------------------------------------------------------ 2
TEST_CASE ( "TP2_Nuage::Iterateurs" ) {
 Polar p1(12,34);
 Polar p2(56,78);
 Polar p3(90,12);
 Polar p4(34,56);

 Nuage<Polar> n;

 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Polar t[4];
 unsigned i = 0;
 Nuage<Polar>::const_iterator it = n.begin();

 while (it!=n.end()) t[i++]=**(it++);

 REQUIRE ( t[0].getAngle() == Approx(p1.getAngle()) );
 REQUIRE ( t[0].getDistance() == Approx(p1.getDistance()) );
 REQUIRE ( t[1].getAngle() == Approx(p2.getAngle()) );
 REQUIRE ( t[1].getDistance() == Approx(p2.getDistance()) );
 REQUIRE ( t[2].getAngle() == Approx(p3.getAngle()) );
 REQUIRE ( t[2].getDistance() == Approx(p3.getDistance()) );
 REQUIRE ( t[3].getAngle() == Approx(p4.getAngle()) );
 REQUIRE ( t[3].getDistance() == Approx(p4.getDistance()) );
}

//------------------------------------------------------------------------------------------------ 3
TEST_CASE ( "TP2_Nuage::BarycentreCartesien_V1" ) {
 Nuage<Cartesian> n;

 Cartesian p1(12,34);
 Cartesian p2(56,78);
 Cartesian p3(90,12);
 Cartesian p4(34,56);

 Cartesian b1 = barycentre_v1(n);

 REQUIRE ( b1.getX() == Approx(0.0) );
 REQUIRE ( b1.getY() == Approx(0.0) );

 n.ajouter(p1);

 Cartesian b2 = barycentre_v1(n);

 REQUIRE ( b2.getX() == Approx(p1.getX()) );
 REQUIRE ( b2.getY() == Approx(p1.getY()) );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Cartesian b3 = barycentre_v1(n);

 REQUIRE ( b3.getX() == Approx((p1.getX()+p2.getX()+p3.getX()+p4.getX())/4) );
 REQUIRE ( b3.getY() == Approx((p1.getY()+p2.getY()+p3.getY()+p4.getY())/4) );
}

//----------------------------------------------------------------------------------------------- 4a
/*TEST_CASE ( "TP2_Nuage::BarycentrePolaire_V1" ) {
 Nuage<Polar> n;

 Polar p1(12,34);
 Polar p2(56,78);
 Polar p3(90,12);
 Polar p4(34,56);

 Polar b1 = barycentre_v1(n);

 REQUIRE ( b1.getAngle() == Approx(0.0) );
 REQUIRE ( b1.getDistance() == Approx(0.0) );

 n.ajouter(p1);

 Polar b2 = barycentre_v1(n);

 REQUIRE ( b2.getAngle() == Approx(p1.getAngle()) );
 REQUIRE ( b2.getDistance() == Approx(p1.getDistance()) );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Polar b3 = barycentre_v1(n);

 REQUIRE ( b3.getAngle() == Approx(43.017260).epsilon(1e-3) );
 REQUIRE ( b3.getDistance() == Approx(42.159772).epsilon(1e-3) );
}*/

//----------------------------------------------------------------------------------------------- 4b
TEST_CASE ( "TP2_Nuage::BarycentrePolaire_V1" ) {
 Nuage<Polar> n;

 Polar p1(12,34);
 Polar p2(56,78);
 Polar p3(90,12);
 Polar p4(34,56);

 Polar b1 = barycentre_v1(n);

 REQUIRE ( b1.getAngle() == Approx(0.0) );
 REQUIRE ( b1.getDistance() == Approx(0.0) );

 n.ajouter(p1);

 Polar b2 = barycentre_v1(n);

 REQUIRE ( b2.getAngle() == Approx(p1.getAngle()) );
 REQUIRE ( b2.getDistance() == Approx(p1.getDistance()) );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Polar b3 = barycentre_v1(n);

 REQUIRE ( b3.getAngle() == Approx((p1.getAngle()+p2.getAngle()
                                   +p3.getAngle()+p4.getAngle())/4) );

 REQUIRE ( b3.getDistance() == Approx((p1.getDistance()+p2.getDistance()
                                      +p3.getDistance()+p4.getDistance())/4) );
}

//------------------------------------------------------------------------------------------------ 5
/*TEST_CASE ( "TP2_Nuage::BarycentreCartesien_V2" ) {
 Nuage<Cartesian> n;

 Cartesian p1(12,34);
 Cartesian p2(56,78);
 Cartesian p3(90,12);
 Cartesian p4(34,56);

 Cartesian b1 = barycentre_v2(n);

 REQUIRE ( b1.getX() == Approx(0.0) );
 REQUIRE ( b1.getY() == Approx(0.0) );

 n.ajouter(p1);

 Cartesian b2 = barycentre_v2(n);

 REQUIRE ( b2.getX() == Approx(p1.getX()) );
 REQUIRE ( b2.getY() == Approx(p1.getY()) );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Cartesian b3 = barycentre_v2(n);

 REQUIRE ( b3.getX() == Approx((p1.getX()+p2.getX()+p3.getX()+p4.getX())/4) );
 REQUIRE ( b3.getY() == Approx((p1.getY()+p2.getY()+p3.getY()+p4.getY())/4) );
}*/

//------------------------------------------------------------------------------------------------ 6
/*TEST_CASE ( "TP2_Nuage::BarycentreCartesienVecteur" ) {
 std::vector<Cartesian> n;

 Cartesian p1(12,34);
 Cartesian p2(56,78);
 Cartesian p3(90,12);
 Cartesian p4(34,56);

 Cartesian b1 = barycentre_v2(n);

 REQUIRE ( b1.getX() == Approx(0.0) );
 REQUIRE ( b1.getY() == Approx(0.0) );

 n.push_back(p1);

 Cartesian b2 = barycentre_v2(n);

 REQUIRE ( b2.getX() == Approx(p1.getX()) );
 REQUIRE ( b2.getY() == Approx(p1.getY()) );

 n.push_back(p2);
 n.push_back(p3);
 n.push_back(p4);

 Cartesian b3 = barycentre_v2(n);

 REQUIRE ( b3.getX() == Approx((p1.getX()+p2.getX()+p3.getX()+p4.getX())/4) );
 REQUIRE ( b3.getY() == Approx((p1.getY()+p2.getY()+p3.getY()+p4.getY())/4) );
}*/

//------------------------------------------------------------------------------------------------ 7
/*TEST_CASE ( "TP2_Nuage::BarycentrePolaire_V2" ) {
 std::vector<Polar> n;

 Polar p1(12,34);
 Polar p2(56,78);
 Polar p3(90,12);
 Polar p4(34,56);

 Polar b1 = barycentre_v2(n);

 REQUIRE ( b1.getAngle() == Approx(0.0) );
 REQUIRE ( b1.getDistance() == Approx(0.0) );

 n.push_back(p1);

 Polar b2 = barycentre_v2(n);

 REQUIRE ( b2.getAngle() == Approx(p1.getAngle()) );
 REQUIRE ( b2.getDistance() == Approx(p1.getDistance()) );

 n.push_back(p2);
 n.push_back(p3);
 n.push_back(p4);

 Polar b3 = barycentre_v2(n);

 REQUIRE ( b3.getAngle() == Approx(43.017260).epsilon(1e-3) );
 REQUIRE ( b3.getDistance() == Approx(42.159772).epsilon(1e-3) );
}*/

// Fin //-------------------------------------------------------------------------------------------
