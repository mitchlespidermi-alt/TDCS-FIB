/*
 * InverterTwF_sid.h
 *
 * Code generation for model "InverterTwF_sf".
 *
 * Model version              : 1.155
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 10:51:13 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: InverterTwF_sf.c
 */

/* statically allocated instance data for model: InverterTwF */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_InverterTwF_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_InverterTwF_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1711520304U);
    ssSetChecksumVal(rts, 1, 3739387201U);
    ssSetChecksumVal(rts, 2, 2672229225U);
    ssSetChecksumVal(rts, 3, 131944791U);
  }
}
