/*
 * InverterTuN_sid.h
 *
 * Code generation for model "InverterTuN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:24:22 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: InverterTuN_sf.c
 */

/* statically allocated instance data for model: InverterTuN */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_InverterTuN_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_InverterTuN_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1301705298U);
    ssSetChecksumVal(rts, 1, 3712248124U);
    ssSetChecksumVal(rts, 2, 999886133U);
    ssSetChecksumVal(rts, 3, 1299013325U);
  }
}
