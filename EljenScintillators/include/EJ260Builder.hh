#ifndef EJ260Builder_h
#define EJ260Builder_h 1

#include "VMaterialBuilder.hh"

class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class EJ260Builder: public VMaterialBuilder{

  public:
    EJ260Builder(G4bool enableOpticalProperty=false); 
    virtual ~EJ260Builder();

    virtual G4Material* Build() override;
       
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

