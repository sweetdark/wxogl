#include "canvassetting.h"

CanvasSetting* CanvasSetting::m_setting = 0;

CanvasSetting::CanvasSetting() : m_lineWidth(1), m_type(PT_Line) {}

CanvasSetting::~CanvasSetting() {}