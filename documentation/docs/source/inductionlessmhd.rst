Inductionless MHD equations
===========================

The MHD equations for an inductionless system with an incompressible fluid can be
broken up into 3 main equations, momentum, incompressibility and something law.

.. math:: \rho \frac{\partial \vec{u}}{\partial t} + \rho \left( \vec{u} \cdot \nabla \vec{u} \right) \vec{u} -\rho \nu \nabla^{2} \vec{u} + \nabla P - \sigma \left(\vec{u} \times \vec{B_{0}} - \nabla \phi \right) \times \vec{B_{0}} = 0
   :label: inductionlessIcoMomentum

.. math:: \nabla \cdot \vec{u} = 0
   :label: incompressibility

.. math:: \nabla^{2} \phi - \nabla \cdot \left( \vec{u} \times \vec{B_{0}} \right) = 0
   :label: incompressibility

.. autosummary::
   :toctree: generated



   lumache
