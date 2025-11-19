/*
 * InverterTvN_sid.h
 *
 * Code generation for model "InverterTvN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:24:41 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: InverterTvN_sf.c
 */

/* statically allocated instance data for model: InverterTvN */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_InverterTvN_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_InverterTvN_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 3255659251U);
    ssSetChecksumVal(rts, 1, 331639415U);
    ssSetChecksumVal(rts, 2, 1782589292U);
    ssSetChecksumVal(rts, 3, 1724025935U);
  }
}
