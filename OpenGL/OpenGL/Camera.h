#ifndef CAMERA_H
#define CAMERA_H

#include "Object.h"
#include "Variables.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class CCamera : IObject
{
public:
	inline CCamera(const int& a_iWidth, const int& a_iHeight, const glm::vec3& a_pos, const glm::vec3& a_orient, const glm::vec3& a_up)
		: m_iWidth{a_iWidth}, m_iHeight{a_iHeight}, m_position{a_pos}, m_orientation{a_orient}, m_up{a_up}	{}
	
	inline void SetData(const CameraData& a_data) { m_data = a_data; }
	inline void SetPosition(const glm::vec3 a_pos) { m_position = a_pos; }
	inline void TranslatePosition(const glm::vec3 a_pos) { m_position += a_pos; }

	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual const int Update(void) override;
	virtual const int Draw(void) override;
	virtual void Finalize(void) override;

private:
	int m_iWidth = 0;
	int m_iHeight = 0;

	glm::mat4x4 m_view = {};
	glm::mat4x4 m_projection = {};
	glm::mat4x4 m_model = {};
	glm::vec3 m_position = {};
	glm::vec3 m_orientation = {};
	glm::vec3 m_up = {};

	CameraData m_data = {};
};

#endif // !CAMERA_H


