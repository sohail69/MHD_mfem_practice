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
(shape-function) and a set of discrete field variables. Each field variable is
assumed to have a unique interpolation weight function.

:math:`u_{i} = N_{im} \tilde{u}_{m}` (continuous approximation to discretised velocity field)

:math:`p = L_{r} \tilde{p}_{r}` (continuous approximation to discretised pressure field)

:math:`\phi = H_{q} \tilde{\phi}_{q}` (continuous approximation to discretised potential field)

The discrete variables are denoted with a tilde over them, from inspection of the govering equations
it can be seen that the  discretized equations have a matrix-vector structure as
follows:


.. math:: M_{ij} \dot{\tilde{Y}}_{j} + \left( K^{C}_{ij} + K^{V}_{ij} \right) \tilde{Y}_{j} = F_{i}
   :label: matrixvectorstructure


In the matrix vector equation above :math:`M_{ij}` is the mass matrix, :math:`K^{C}_{ij}` is the constant/linear 
component of the stiffness matrix, :math:`K^{V}_{ij}` is the variable/non-linear component of the stiffness matrix.
:math:`\dot{\tilde{Y}}_{j}` are the discrete field rates, :math:`\tilde{Y}_{j}` are the discrete field variables 
and, :math:`F_{i}` are the discrete field forcing terms.

* :math:`\dot{\tilde{Y}} = \left(\dot{\tilde{u}} , \dot{\tilde{p}}, \dot{\tilde{\phi}}  \right)` discrete field rates

* :math:`\tilde{Y} = \left(\tilde{u} , \tilde{p}, \tilde{\phi}  \right)` discrete field variables

The matrix-vector structure can be further expanded into a block-matrix vector structure for each of the field variables
as follows:


.. math:: \begin{pmatrix} M_{11} & 0 & 0 \\ 0 & 0 & 0 \\ 0 & 0 & 0 \end{pmatrix} 
          \begin{pmatrix} \dot{\tilde{u}} \\ \dot{\tilde{p}} \\ \dot{\tilde{\phi}} \end{pmatrix}  +
          \left[
          \begin{pmatrix} K^{C}_{11} & 0 & K^{C}_{13} \\ K^{C}_{21} & 0 & 0 \\ 0 & K^{C}_{32} & 0 \end{pmatrix} +
          \begin{pmatrix} K^{V}_{11} & K^{V}_{12} & 0 \\ 0 & 0 & 0 \\ K^{V}_{31} & 0 & 0 \end{pmatrix}
          \right]
          \begin{pmatrix} \tilde{u} \\ \tilde{p} \\ \tilde{\phi} \end{pmatrix}  =
          \begin{pmatrix} \tilde{f_{1}} \\ \tilde{f_{2}} \\ \tilde{f_{3}} \end{pmatrix}  
   :label: blockmatrixvectorstructure


Weak forms of the equation
---------------------------
The matrix blocks can be interpreted as unique(ish) weak forms of the jacobian, and can be expanded out
into integral equations. Integrating and assembling the matrix blocks gives the complete set of matrix 
equations needed to solve the discrete field equations.

**Mass matrix components**


.. math:: (M_{11})_{mn} = \int_{\Omega} \rho N_{im} N_{in} d\Omega
   :label: massmatrix

**Constant/linear-stiffness matrix components**


.. math:: (K^{C}_{11})_{mn} = \int_{\Omega} \rho \nu \nabla N_{im} \nabla N_{in} d\Omega - \int_{\partial \Omega} \rho \nu \nabla N_{im} N_{in} \cdot \vec{n} dS
   :label: conststiffness11


.. math:: (K^{C}_{13})_{mn} = \int_{\Omega}  \nabla L_{n} N_{im} d\Omega
   :label: conststiffness13


.. math:: (K^{C}_{21})_{mn} = \int_{\Omega} \nabla \cdot N_{in} L_{m} d\Omega
   :label: conststiffness21


.. math:: (K^{C}_{32})_{mn} = \int_{\Omega} \nabla H_{m} \nabla H_{n} d\Omega -  \int_{\partial \Omega} \nabla H_{m} H_{n} \cdot \vec{n} dS
   :label: conststiffness32


**Variable/non-linear-stiffness matrix components**


.. math:: (K^{V}_{11})_{mn} = \int_{\Omega} \left( N_{im} \times \vec{B}_{0}  \right) \times \vec{B}_{0} \cdot N_{im} d\Omega
   :label: varstiffness11


.. math:: (K^{V}_{13})_{mn} = \int_{\Omega} - \left( \nabla L_{n} \times \vec{B}_{0} \right) \cdot N_{im} d\Omega
   :label: varstiffness13


.. math:: (K^{V}_{31})_{mn} = \int_{\Omega} \nabla \cdot \left(N_{im} \times \vec{B}_{0} \right) \cdot L_{m} d\Omega
   :label: varstiffness31


.. autosummary::
   :toctree: generated



   lumache
