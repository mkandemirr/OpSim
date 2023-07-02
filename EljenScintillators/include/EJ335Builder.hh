#ifndef EJ335Builder_h
#define EJ335Builder_h 1

#include "VMaterialBuilder.hh"

class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class EJ335Builder: public VMaterialBuilder{

  public:
    EJ335Builder(G4bool enableOpticalProperty=false); 
    virtual ~EJ335Builder();

    virtual G4Material* Build() override;
       
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

