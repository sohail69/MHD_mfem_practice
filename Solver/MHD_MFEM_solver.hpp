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

    


}
