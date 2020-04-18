#include <iostream>
#include <math.h>
#include "plana.h"
#include "keyvalue.h"

#include <stdlib.h>

using namespace upc;
using namespace std;

plana::plana(const std::string &param) 
  : adsr(SamplingRate, param) {
  bActive = false;
  x.resize(BSIZE);

  /*
    You can use the class keyvalue to parse "param" and configure your instrument.
    Take a Look at keyvalue.h    
  */
  
  KeyValue kv(param);
  int N;

  if (!kv.to_int("N",N))
    N = 40; //default value
  
  //Create a tbl with one period of a sinusoidal wave
  tbl.resize(N);
  float phase = 0, step = 2 * M_PI /(float) N;
  index = 0;
  for (int i=0; i < N ; ++i) {
    tbl[i] = sin(phase);
    
    phase += step;
  }
}


void plana::command(long cmd, long note, long vel) {
  if (cmd == 9) {		//'Key' pressed: attack begins
    bActive = true;
    adsr.start();
    index = 0;
    f0=(pow(2,(note-69)/12.))*440;
    pass = (tbl.size()/(double) SamplingRate)*f0 ; 
  	A = vel / 127.;
  }
  else if (cmd == 8) {	//'Key' released: sustain ends, release begins
    adsr.stop();
  }
  else if (cmd == 0) {	//Sound extinguished without waiting for release to end
    adsr.end();
  }
}


const vector<float> & plana::synthesize() {
  if (not adsr.active()) {
    x.assign(x.size(), 0);
    bActive = false;
    return x;
  }
  else if (not bActive)
    return x;
//FILE *f =fopen("prueba.txt", "w");
  for (unsigned int i=0; i<x.size(); ++i) {
    index = index + pass;
    
    x[i] = A * tbl[index++];
   //  fprintf(f, "%f %f %d %f \n", f0, pass, index, x[i]);

    if (index == tbl.size())
      index = 0;
  }
  adsr(x); //apply envelope to x and update internal status of ADSR
  //fclose(f);
  return x;
}