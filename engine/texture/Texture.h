#pragma once

#include "EBO.h"
#include "VAO.h"
#include "ZeroShader.h"
#include "tim2.h"

struct Tim2Converted
{
  int Height;
  int Width;
  char *image;
};

struct TextureVertex
{
  GLfloat coordX;
  GLfloat coordY;
  GLfloat coordZ;
  GLfloat r;
  GLfloat g;
  GLfloat b;
  GLfloat texCoordX;
  GLfloat texCoordY;
};

struct TextureInfo
{
  int numVertex;
  TextureVertex* vertices;
  int numIndex;
  GLuint* indices;
};

Tim2Converted *LoadTim2Texture(TIM2_FILEHEADER *pTim2FileHeader);

class Texture
{
 public:
  GLuint ID;
  GLenum type;
  Texture(TIM2_FILEHEADER *pTim2FileHeader, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
  void texUnit(Shader *shader, const char* uniform, GLuint unit);
  void Bind();
  void Unbind();
  void Delete();
};

class Texture2d
{
 public:
  Texture2d(TIM2_FILEHEADER* pTim2FileHeader, GLenum slot);
  void InitTexture(TextureInfo* textureInfo);
  void RenderTexture();

 private:
  TIM2_FILEHEADER* pTim2FileHeader;
  GLenum slot;
  VAO *VAO1;
  EBO *EBO1;
  VBO *VBO1;
  Shader *shaderProgram;
  Texture *texture;
  GLuint uniID;
};