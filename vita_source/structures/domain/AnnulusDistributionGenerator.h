/* SPDX-License-Identifier: Apache-2.0 */
/* AnnulusDistributionGenerator.h
 *
 *  Created on: 07/03/2023
 *      Author: Remi Hernandez
 */

#ifndef DOMAIN_ANNULUSDISTRIBUTIONGENERATOR_H_
#define DOMAIN_ANNULUSDISTRIBUTIONGENERATOR_H_

#include "DistributionGenerator.h"
// #include <cmath>

class AnnulusDistributionGenerator: public DistributionGenerator {
	/**	Generator for theta component */
	uniform_real_distribution<double> theta;
	/**	Generator for phi component */
	uniform_real_distribution<double> z;
	/**	Generator for radius component */
  // uniform_real_distribution<double> radius;
        normal_distribution<double> radius;
        /**     Center of the annulus (i.e., the FAZ) */
	point center;
	/**     Inner radius of the annulus */
	double innerRadius;
        /** Parameter of the lognormal distribution */
        double mu;
        /** Parameter of the lognormal distribution */
        double sigma;
	    
public:
	/**
	 * Constructor.
	 * @param rad The the inner radius of the annulus.
	 * @param k The power law coefficient.
	 */
        AnnulusDistributionGenerator(double rad, double center[3], double mu, double sigma);
	/**
	 * Destructor.
	 */
	virtual ~AnnulusDistributionGenerator();
	/**
	 * Initializer of the generator. Execute it before any getter call is performed.
	 */
	virtual void initialize(int seed, double *boundingBox);
	/**
	 * Return a vector of @p n points of the distribution.
	 * @param n Amount of output points.
	 * @return Vector of distribution points.
	 */
	vector<point> getNPoints(int n);
};


class SCPDistributionGenerator: public DistributionGenerator {
	/**	Generator for theta component */
	uniform_real_distribution<double> theta;
	/**	Generator for phi component */
	normal_distribution<double> z;
	/**	Generator for radius component */
  // uniform_real_distribution<double> radius;
        normal_distribution<double> radius;
        /**     Center of the annulus (i.e., the FAZ) */
	point center;
	/**     Inner radius of the annulus */
	double innerRadius;
        /** Parameter of the lognormal distribution */
        double mu;
        /** Parameter of the lognormal distribution */
        double sigma;
        /** Parameter of the normal distribution */
        double mu_z;
        /** Parameter of the normal distribution */
        double sigma_z;

	    
public:
	/**
	 * Constructor.
	 * @param rad The the inner radius of the annulus.
	 * @param k The power law coefficient.
	 */
        SCPDistributionGenerator(double rad, double center[3],
				 double mu, double sigma,
				 double mu_z, double sigma_z);
	/**
	 * Destructor.
	 */
	virtual ~SCPDistributionGenerator();
	/**
	 * Initializer of the generator. Execute it before any getter call is performed.
	 */
	virtual void initialize(int seed, double *boundingBox);
	/**
	 * Return a vector of @p n points of the distribution.
	 * @param n Amount of output points.
	 * @return Vector of distribution points.
	 */
	vector<point> getNPoints(int n);
};


#endif /* DOMAIN_ANNULUSDISTRIBUTIONGENERATOR_H_ */
