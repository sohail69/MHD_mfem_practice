/*
 Solver header file
 for an inductionless MHD solver
*/

class MHD_solver : public TimeDependentOperator
{
  public:
    MHD_Solver();

    ~MHD_Solver();

    int GetLogging() const {return logging_;};
    void SetLogging(int logging){logging_ = logging; };

  private:

    ParGridFunction * u_;   //velocity field
    ParGridFunction * p_;   //pressure field
    ParGridFunction * phi_; //velocity field

    HypreParMatrix M11;     //Velocity Mass matrix
    


}
