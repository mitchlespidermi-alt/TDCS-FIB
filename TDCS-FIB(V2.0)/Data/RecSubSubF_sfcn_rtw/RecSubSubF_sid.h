/*
 * RecSubSubF_sid.h
 *
 * Code generation for model "RecSubSubF_sf".
 *
 * Model version              : 1.160
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:16:51 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: RecSubSubF_sf.c
 */

/* statically allocated instance data for model: RecSubSubF */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_RecSubSubF_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_RecSubSubF_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1031741443U);
    ssSetChecksumVal(rts, 1, 2386152078U);
    ssSetChecksumVal(rts, 2, 3072601784U);
    ssSetChecksumVal(rts, 3, 2589774467U);
  }
}
