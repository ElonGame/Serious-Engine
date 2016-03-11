/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 7 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"

#include "StdH.h"

#include <EntitiesMP/SoundHolder.h>
#include <EntitiesMP/SoundHolder_tables.h>
void CSoundHolder::SetDefaultProperties(void) {
  m_fnSound = CTFILENAME("Sounds\\Default.wav");
  m_rFallOffRange = 100.0f;
  m_rHotSpotRange = 50.0f;
  m_fVolume = 1.0f;
  m_bLoop = TRUE ;
  m_bSurround = FALSE ;
  m_bVolumetric = TRUE ;
  m_strName = "";
  m_strDescription = "";
  m_bAutoStart = FALSE ;
  m_iPlayType = 0;
  m_soSound.SetOwner(this);
m_soSound.Stop_internal();
  m_bDestroyable = FALSE ;
  CRationalEntity::SetDefaultProperties();
}
  
#line 48 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
void CSoundHolder::Precache(void) 
#line 49 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
{
#line 50 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
m_aps  . Precache  (m_fnSound );
#line 51 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
}
  
#line 54 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
void CSoundHolder::MirrorAndStretch(FLOAT fStretch,BOOL bMirrorX) 
#line 55 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
{
#line 57 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
m_rFallOffRange  *= fStretch ;
#line 58 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
m_rHotSpotRange  *= fStretch ;
#line 60 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
}
  
#line 64 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
SLONG CSoundHolder::GetUsedMemory(void) 
#line 65 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
{
#line 67 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
SLONG  slUsedMemory  = sizeof  (CSoundHolder ) - sizeof  (CRationalEntity ) + CRationalEntity  :: GetUsedMemory  ();
#line 69 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
slUsedMemory  += m_strName  . Length  ();
#line 70 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
slUsedMemory  += m_strDescription  . Length  ();
#line 71 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
slUsedMemory  += m_fnSound  . Length  ();
#line 72 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
slUsedMemory  += 1 * sizeof  (CSoundObject);
#line 73 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
return slUsedMemory ;
#line 74 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
}
BOOL CSoundHolder::
#line 80 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CSoundHolder_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CSoundHolder::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 83 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
if(m_rHotSpotRange  < 0.0f){m_rHotSpotRange  = 0.0f;}
#line 84 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
if(m_rFallOffRange  < m_rHotSpotRange ){m_rFallOffRange  = m_rHotSpotRange ;}
#line 86 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
if(m_fVolume  < FLOAT (SL_VOLUME_MIN )){m_fVolume  = FLOAT (SL_VOLUME_MIN );}
#line 87 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
if(m_fVolume  > FLOAT (SL_VOLUME_MAX )){m_fVolume  = FLOAT (SL_VOLUME_MAX );}
#line 90 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
m_iPlayType  = SOF_3D ;
#line 91 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
if(m_bLoop ){m_iPlayType  |= SOF_LOOP ;}
#line 92 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
if(m_bSurround ){m_iPlayType  |= SOF_SURROUND ;}
#line 93 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
if(m_bVolumetric ){m_iPlayType  |= SOF_VOLUMETRIC ;}
#line 96 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
InitAsEditorModel  ();
#line 97 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 98 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 101 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
const float  SOUND_MINSIZE  = 1.0f;
#line 102 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
FLOAT fFactor  = Log2  (m_rFallOffRange ) * SOUND_MINSIZE ;
#line 103 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
if(fFactor  < SOUND_MINSIZE ){
#line 104 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
fFactor  = SOUND_MINSIZE ;
#line 105 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
}
#line 106 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
GetModelObject  () -> mo_Stretch  = FLOAT3D (fFactor  , fFactor  , fFactor );
#line 109 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
SetModel  (MODEL_MARKER );
#line 110 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
SetModelMainTexture  (TEXTURE_MARKER );
#line 112 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
m_strDescription  . PrintF  ("%s" , (CTString &) m_fnSound  . FileName  ());
#line 115 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
if(!(_pTimer  -> CurrentTick  () <= 0.1f)){ Jump(STATE_CURRENT,0x00cc0002, FALSE, EInternal());return TRUE;}
#line 117 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
SetTimerAfter(0.5f);
Jump(STATE_CURRENT, 0x00cc0000, FALSE, EBegin());return TRUE;}BOOL CSoundHolder::H0x00cc0000_Main_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00cc0000
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x00cc0001, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CSoundHolder::H0x00cc0001_Main_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00cc0001
;Jump(STATE_CURRENT,0x00cc0002, FALSE, EInternal());return TRUE;}BOOL CSoundHolder::H0x00cc0002_Main_03(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00cc0002

#line 120 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
SetTimerAt(THINKTIME_NEVER);
Jump(STATE_CURRENT, 0x00cc0003, FALSE, EBegin());return TRUE;}BOOL CSoundHolder::H0x00cc0003_Main_04(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x00cc0003
switch(__eeInput.ee_slEvent){case(EVENTCODE_EBegin):{const EBegin&e= (EBegin&)__eeInput;

#line 123 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
if(m_bAutoStart ){
#line 124 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
m_soSound  . Set3DParameters  (FLOAT (m_rFallOffRange ) , FLOAT (m_rHotSpotRange ) , m_fVolume  , 1.0f);
#line 125 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
PlaySound  (m_soSound  , m_fnSound  , m_iPlayType );
#line 126 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
}
#line 127 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
return TRUE;
#line 128 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStart):{const EStart&e= (EStart&)__eeInput;

#line 131 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
m_soSound  . Set3DParameters  (FLOAT (m_rFallOffRange ) , FLOAT (m_rHotSpotRange ) , m_fVolume  , 1.0f);
#line 132 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
PlaySound  (m_soSound  , m_fnSound  , m_iPlayType );
#line 133 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
return TRUE;
#line 134 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EStop):{const EStop&e= (EStop&)__eeInput;

#line 137 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
m_soSound  . Stop  ();
#line 138 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
return TRUE;
#line 139 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_ERangeModelDestruction):{const ERangeModelDestruction&e= (ERangeModelDestruction&)__eeInput;

#line 143 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
if(m_bDestroyable ){
#line 145 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
m_soSound  . Stop  ();
#line 146 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
}
#line 147 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
Return(STATE_CURRENT,TRUE );
#line 147 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
return TRUE;
#line 148 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
}ASSERT(FALSE);break;case(EVENTCODE_EEnd):{const EEnd&e= (EEnd&)__eeInput;
UnsetTimer();Jump(STATE_CURRENT,0x00cc0004, FALSE, EInternal());return TRUE;}ASSERT(FALSE);break;default: return FALSE; break;
#line 150 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
}return TRUE;}BOOL CSoundHolder::H0x00cc0004_Main_05(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x00cc0004

#line 153 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
Destroy  ();
#line 154 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
Return(STATE_CURRENT,EVoid());
#line 154 "D:/SE1_GPL/Sources/EntitiesMP/SoundHolder.es"
return TRUE; ASSERT(FALSE); return TRUE;};