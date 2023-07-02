
#ifndef EJ200Builder_h
#define EJ200Builder_h 1

#include "VMaterialBuilder.hh"

class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class EJ200Builder: public VMaterialBuilder{

  public:
    EJ200Builder(G4bool enableOpticalProperty=false); 
    virtual ~EJ200Builder();

  protected:
    virtual G4Material* Build() override;
       
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

