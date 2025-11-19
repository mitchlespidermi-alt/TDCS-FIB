/*
 * SAN_sid.h
 *
 * Code generation for model "SAN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:22:40 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: SAN_sf.c
 */

/* statically allocated instance data for model: SAN */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_SAN_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_SAN_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 1342987738U);
    ssSetChecksumVal(rts, 1, 1289489414U);
    ssSetChecksumVal(rts, 2, 1469030365U);
    ssSetChecksumVal(rts, 3, 2837321638U);
  }
}
