/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "Residual.h"

#include "FEProblem.h"
#include "SubProblem.h"

template<>
InputParameters validParams<Residual>()
{
  InputParameters params = validParams<GeneralPostprocessor>();
  return params;
}

Residual::Residual(const InputParameters & parameters) :
    GeneralPostprocessor(parameters)
{}

Real
Residual::getValue()
{
  return _subproblem.finalNonlinearResidual();
}

