#ifndef EJ426Builder_h
#define EJ426Builder_h 1

#include "VMaterialBuilder.hh"

class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class EJ426Builder: public VMaterialBuilder{

  public:
    EJ426Builder(G4bool enableOpticalProperty=false); 
    virtual ~EJ426Builder();

    virtual G4Material* Build() override;
       
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

