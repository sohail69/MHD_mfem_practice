Inductionless MHD equations
===========================
The MHD equations for an inductionless system with an incompressible fluid can be
broken up into 3 main equations, momentum, incompressibility and something law.

Strong form of the equations
----------------------------
The equations in the strong form can be given as a set of 3-differential equations:

.. math:: \rho \frac{\partial \vec{u}}{\partial t} + \rho \left( \vec{u} \cdot \nabla \right) \vec{u} -\rho \nu \nabla^{2} \vec{u} + \nabla p - \sigma \left(\vec{u} \times \vec{B_{0}} - \nabla \phi \right) \times \vec{B_{0}} = 0
   :label: inductionlessIcoMomentum

.. math:: \nabla \cdot \vec{u} = 0
   :label: incompressibility

.. math:: \nabla^{2} \phi - \nabla \cdot \left( \vec{u} \times \vec{B_{0}} \right) = 0
   :label: incompressibility

There variables can be broken up into a 3 categories: the first is field variables (to be solved for)
, the second are field varying constants (material properties etc..) and the third categoriy is applied source field variables.

**Field Variables**:

* $ \vec{u} $ = the vector velocity field

* $ p $ = The scalar pressure field

* $ \phi $ = The scalar electric potential field

**Field varying constants**:

* $ \rho $ = fluid density

* $ \nu $ = Kinematic viscosity

* $\sigma$ = conductivity

**Applied source field variable**:

* $ \vec{B_{0}} $ = Applied vector B-field

Discretisation of variables
---------------------------


.. autosummary::
   :toctree: generated



   lumache
