#pragma once
#include "Utillity.h"

namespace transform {
	struct Transform
	{
		using Vector2f = learning::Vector2f;

		Vector2f position;
		float rotation;
		Vector2f scale;

		Transform() {
			position = Vector2f(0.0f, 0.0f);
			rotation = 0.0f;
			scale = Vector2f(1.0f, 1.0f);
		}
		Transform(Vector2f position, float rotation, Vector2f scale)
			: position(position), rotation(rotation), scale(scale) { }

		// 값 수정
		void SetPosition(Vector2f value) {
			position = value;
		}
		void ModifyPosition(Vector2f value) {
			position += value;
		}
		void SetRotation(float value) {
			rotation = value;
		}
		void ModifyRotation(float value) {
			rotation += value;
		}
		void SetScale(Vector2f value) {
			scale = value;
		}
		void ModifyScale(Vector2f value) {
			scale += value;
		}

		// 연산자 오버로딩
		Transform operator+(const Transform& other) const {
			return Transform(
				position + other.position,
				rotation + other.rotation,
				scale * other.scale			// 크기만 곱셈으로 연산
			);
		}
	};
}
