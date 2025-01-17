/* SPDX-License-Identifier: Apache-2.0 */
/*
 * AnnulusDistributionGenerator.cpp
 *
 *  Created on: 07/03/2023
 *      Author: Remi Hernandez
 */

#include "AnnulusDistributionGenerator.h"

AnnulusDistributionGenerator::AnnulusDistributionGenerator(double rad, double center[3],
							   double mu, double sigma) : DistributionGenerator(){
  this->innerRadius = rad;
  this->center = {center[0], center[1], center[2]};
  this->mu = mu;
  this->sigma = sigma;
}

AnnulusDistributionGenerator::~AnnulusDistributionGenerator(){
}

void AnnulusDistributionGenerator::initialize(int seed, double *boundingBox) {
	DistributionGenerator::initialize(seed, boundingBox);
	
	theta  = uniform_real_distribution<double>(0, 2.0*M_PI);
	radius = normal_distribution<double>(0,1); // Standard normal dist.
	z = uniform_real_distribution<double>(boundingBox[4], boundingBox[5]);
}

vector<point> AnnulusDistributionGenerator::getNPoints(int n){
	vector<point> randomInnerPoints;
	for (int i = 0; i < n; ++i) {
	  double a = theta(generator);
	  double r = exp(this->mu +
			 this->sigma*radius(generator))
	    +this->innerRadius; // Make a lognormal distribution
	  point p = {r*cos(a), r*sin(a), 0.0};
	  randomInnerPoints.push_back(p);//+this->center);
	}
	return randomInnerPoints;
}


SCPDistributionGenerator::SCPDistributionGenerator(double rad, double center[3],
						   double mu, double sigma,
						   double mu_z, double sigma_z) : DistributionGenerator(){
  this->innerRadius = rad;
  this->center = {center[0], center[1], center[2]};
  this->mu = mu;
  this->sigma = sigma;
  this->mu_z = mu_z;
  this->sigma_z = sigma_z;
}

SCPDistributionGenerator::~SCPDistributionGenerator(){
}

void SCPDistributionGenerator::initialize(int seed, double *boundingBox) {
	DistributionGenerator::initialize(seed, boundingBox);
	
	theta  = uniform_real_distribution<double>(0, 2.0*M_PI);
	radius = normal_distribution<double>(0,1); // Standard normal dist.
	z = normal_distribution<double>(this->mu_z, this->sigma_z);
}

vector<point> SCPDistributionGenerator::getNPoints(int n){
	vector<point> randomInnerPoints;
	for (int i = 0; i < n; ++i) {
	  double a = theta(generator);
	  double r = exp(this->mu +
			 this->sigma*radius(generator))
	    +this->innerRadius; // Make a lognormal distribution
	  point p = {r*cos(a), r*sin(a), this->z(generator)};
	  randomInnerPoints.push_back(p);//+this->center);
	}
	return randomInnerPoints;
}





// AnnulusDistributionGenerator::AnnulusDistributionGenerator(double rad, double k) : DistributionGenerator(){
//   alpha       = k;
//   innerRadius = pow(rad, alpha+1);
// }

// AnnulusDistributionGenerator::~AnnulusDistributionGenerator(){
// }

// void AnnulusDistributionGenerator::initialize(int seed, double *boundingBox) {
// 	DistributionGenerator::initialize(seed, boundingBox);

//  	outerRadius = pow(fabs(boundingBox[3]-boundingBox[2])/2.0, alpha+1);
// 	point p = {(boundingBox[1]+boundingBox[0])/2.0, (boundingBox[2]+boundingBox[3])/2.0, (boundingBox[4]+boundingBox[5])/2.0};
// 	center = p;
// 	theta  = uniform_real_distribution<double>(0, 2.0*M_PI);
// 	radius = uniform_real_distribution<double>(0.0,1.0);
// 	z = uniform_real_distribution<double>(boundingBox[4], boundingBox[5]);
// }

// vector<point> AnnulusDistributionGenerator::getNPoints(int n){
// 	vector<point> randomInnerPoints;
// 	for (int i = 0; i < n; ++i) {
// 	  double a = theta(generator);
// 	  double r = pow( (outerRadius-innerRadius)*radius(generator) + innerRadius, 1.0/(alpha+1));
// 	  point p = {r*cos(a), r*sin(a), z(generator)};
// 	  randomInnerPoints.push_back(p+center);
// 	}
// 	return randomInnerPoints;
// }
