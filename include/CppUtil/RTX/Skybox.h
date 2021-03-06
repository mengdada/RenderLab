#ifndef _RTX_RT_TEXTURE_SKY_BOX_H_
#define _RTX_RT_TEXTURE_SKY_BOX_H_

#include <CppUtil/RTX/Texture.h>

#include <CppUtil/Basic/Ptr.h>

#include <vector>
#include <string>

namespace CppUtil {
	namespace Basic {
		class Image;
	}
}

namespace RTX {
	class Skybox : public Texture {
		TEXTURE_SETUP(Skybox)
	public:
		typedef std::vector<CppUtil::Basic::CPtr<CppUtil::Basic::Image> > SkyboxImgs;
		//right, left, top, bottom, front, back
		Skybox(const std::vector<std::string> & skybox);
		const SkyboxImgs & GetSkyboxImgs() const { return imgs; }
		bool IsValid() const;
	private:
		virtual glm::vec3 Value(float u = 0, float v = 0, const glm::vec3 & p = glm::vec3(0)) const;
		SkyboxImgs imgs;
	};
}

#endif // !_RTX_RT_TEXTURE_SKY_BOX_H_
