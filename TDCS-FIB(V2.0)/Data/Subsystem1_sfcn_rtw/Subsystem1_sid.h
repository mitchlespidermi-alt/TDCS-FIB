/*
 * Subsystem1_sid.h
 *
 * Code generation for model "Subsystem1_sf".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Jul 04 15:10:17 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: Subsystem1_sf.c
 */

/* statically allocated instance data for model: Subsystem1 */
{
  extern P_Subsystem1_T Subsystem1_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_Subsystem1_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_Subsystem1_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &Subsystem1_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 2930463213U);
    ssSetChecksumVal(rts, 1, 2818168672U);
    ssSetChecksumVal(rts, 2, 1390588008U);
    ssSetChecksumVal(rts, 3, 1626094005U);
  }
}
