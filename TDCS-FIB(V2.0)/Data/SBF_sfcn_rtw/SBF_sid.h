/*
 * SBF_sid.h
 *
 * Code generation for model "SBF_sf".
 *
 * Model version              : 1.160
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:16:01 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: SBF_sf.c
 */

/* statically allocated instance data for model: SBF */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_SBF_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_SBF_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 3901026667U);
    ssSetChecksumVal(rts, 1, 1616378531U);
    ssSetChecksumVal(rts, 2, 1175716113U);
    ssSetChecksumVal(rts, 3, 1743441960U);
  }
}
