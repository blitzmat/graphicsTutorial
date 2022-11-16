#pragma once
#include <string>

#include "GLTexture.h"
#include "TextureCache.h"

namespace Bengine {
	class ResourceManager
	{
	public:
		static GLTexture getTexture(std::string texturePath);

	private:
		static TextureCache _textureCache;
	};

}
