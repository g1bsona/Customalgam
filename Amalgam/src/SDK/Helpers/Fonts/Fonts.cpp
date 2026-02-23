#include "Fonts.h"

void CFonts::Reload(float flDPI)
{
	m_mFonts[FONT_ESP] = { Vars::Fonts::ESPFont::szName.Value.c_str(), int(Vars::Fonts::ESPFont::nTall.Value * flDPI), Vars::Fonts::ESPFont::nFlags.Value, Vars::Fonts::ESPFont::nWeight.Value };
	m_mFonts[FONT_INDICATORS] = { Vars::Fonts::IndicatorFont::szName.Value.c_str(), int(Vars::Fonts::IndicatorFont::nTall.Value * flDPI), Vars::Fonts::IndicatorFont::nFlags.Value, Vars::Fonts::IndicatorFont::nWeight.Value };

	for (auto& [_, fFont] : m_mFonts)
	{
		if (fFont.m_dwFont = I::MatSystemSurface->CreateFont())
			I::MatSystemSurface->SetFontGlyphSet(fFont.m_dwFont, fFont.m_szName, fFont.m_nTall, fFont.m_nWeight, 0, 0, fFont.m_nFlags);
	}
}

const Font_t& CFonts::GetFont(EFonts eFont)
{
	return m_mFonts[eFont];
}