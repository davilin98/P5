#include <iostream>
#include "instrument_dumb.h"
#include "seno.h"
#include "gen.h"
#include "perc.h"
#include "plana.h"
#include "sintesis_fm.h"
/*
  For each new instrument:
  - Add the header in this file
  - Add the call to the constructor in get_instrument() (also in this file)
  - Add the source file to src/meson.build
*/

using namespace std;

namespace upc {
  Instrument * get_instrument(const string &name,
			      const string &parameters) {
    Instrument * pInst = 0;
    //    cout << name << ": " << parameters << endl;
    if (name == "InstrumentDumb") {
      pInst = (Instrument *) new InstrumentDumb(parameters);
    }

     if (name == "Seno") {
      pInst = (Instrument *) new Seno(parameters);
    }
    if (name == "gen"){
      pInst = (Instrument *) new gen(parameters);
    }
    if (name == "perc"){
      pInst = (Instrument *) new perc(parameters);
    }
    if (name == "plana"){
      pInst = (Instrument *) new plana(parameters);
    }
    if (name == "fm"){
      pInst = (Instrument *) new fm(parameters);
    }
    return pInst;
  }
}
