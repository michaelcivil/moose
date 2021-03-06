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

// MOOSE includes
#include "PartitionerAction.h"
#include "MoosePartitioner.h"
#include "FEProblem.h"
#include "MooseEnum.h"
#include "MooseMesh.h"

template<>
InputParameters validParams<PartitionerAction>()
{
  InputParameters params = validParams<MooseObjectAction>();
  return params;
}

PartitionerAction::PartitionerAction(InputParameters params) :
    MooseObjectAction(params)
{
}

void
PartitionerAction::act()
{
  _mesh->setIsCustomPartitionerRequested(true);
  MooseSharedPointer<MoosePartitioner> mp = MooseSharedNamespace::static_pointer_cast<MoosePartitioner>(_factory.create(_type, _name, _moose_object_pars));
  _mesh->setCustomPartitioner(mp.get());
}
