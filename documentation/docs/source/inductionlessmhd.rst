Inductionless MHD equations
===========================
The MHD equations for an inductionless system with an incompressible fluid can be
broken up into 3 main equations, momentum, incompressibility and something law.

Strong form of the equations
----------------------------
The equations in the strong form can be given as a set of 3-differential equations:

.. math:: \rho \frac{\partial \vec{u}}{\partial t} + \rho \left( \vec{u} \cdot \nabla \right) \vec{u} -\rho \nu \nabla^{2} \vec{u} + \nabla p - \sigma \left(\vec{u} \times \vec{B_{0}} - \nabla \phi \right) \times \vec{B_{0}} = 0
   :label: incompressibility

.. math:: \nabla \cdot \vec{u} = 0
   :label: incompressibility

.. math:: \nabla^{2} \phi - \nabla \cdot \left( \vec{u} \times \vec{B_{0}} \right) = 0
   :label: incompressibility

There variables can be broken up into a 3 categories: the first is field variables (to be solved for)
, the second are field varying constants (material properties etc..) and the third categoriy is applied source field variables.

**Field Variables**:

* :math:`\vec{u}` = the vector velocity field

* :math:`p` = The scalar pressure field

* :math:`\phi` = The scalar electric potential field

**Field varying constants**:

* :math:`\rho` = fluid density

* :math:`\nu` = Kinematic viscosity

* :math:`\sigma` = conductivity

**Applied source field variable**:

* :math:`\vec{B_{0}}` = Applied vector B-field

Discretisation of variables and block Matrix-structure
------------------------------------------------------
The field variables can be discretised in terms of an interpolation function weights
(shape-function) and discrete a set of discrete field variables. Each field variable is
assumed to have a unique interpolation weight function.

:math:`u_{i} = N_{im} \tilde{u}_{m}` (continuous approximation to discretised velocity field)

:math:`p = L_{r} \tilde{p}_{r}` (continuous approximation to discretised pressure field)

:math:`\phi = H_{q} \tilde{\phi}_{q}` (continuous approximation to discretised potential field)

The discrete variables are denoted with a tilde over them, the equations can be put into a block matrix structure as
follows:

.. math:: M_{ij} \dot{Y}_{j} + \left( K^{C}_{ij} K^{V}_{ij} \right) Y_{j} = F_{i}
   :label: blockmatrixstructure


Weak forms of the equation
---------------------------
The weak forms of the equation can be arrived at by multiplying the strong forms of the equations
by test functions an integrating, often the test functions can be the interpolation functions. The 3-strong form
equations have 3-corresponding weak form eqautions however the block matrix-structure means that the these can be
further divided into linear and non-linear components.

.. autosummary::
   :toctree: generated



   lumache
