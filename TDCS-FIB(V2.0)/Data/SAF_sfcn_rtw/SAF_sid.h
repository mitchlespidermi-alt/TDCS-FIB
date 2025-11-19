/*
 * SAF_sid.h
 *
 * Code generation for model "SAF_sf".
 *
 * Model version              : 1.160
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:15:36 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: SAF_sf.c
 */

/* statically allocated instance data for model: SAF */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_SAF_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_SAF_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 3275831921U);
    ssSetChecksumVal(rts, 1, 3757540204U);
    ssSetChecksumVal(rts, 2, 3126115885U);
    ssSetChecksumVal(rts, 3, 2399893561U);
  }
}
