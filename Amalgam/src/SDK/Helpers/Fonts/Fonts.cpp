#include "Fonts.h"

void CFonts::Reload(float flDPI)
{
	m_mFonts[FONT_ESP] = { Vars::Fonts::FONT_ESP::szName.Value.c_str(), int(Vars::Fonts::FONT_ESP::nTall.Value * flDPI), Vars::Fonts::FONT_ESP::nFlags.Value, Vars::Fonts::FONT_ESP::nWeight.Value };
	m_mFonts[FONT_INDICATORS] = { Vars::Fonts::FONT_INDICATORS::szName.Value.c_str(), int(Vars::Fonts::FONT_INDICATORS::nTall.Value * flDPI), Vars::Fonts::FONT_INDICATORS::nFlags.Value, Vars::Fonts::FONT_INDICATORS::nWeight.Value };

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