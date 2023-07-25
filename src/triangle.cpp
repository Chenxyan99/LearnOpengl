#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "triangle.h"

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 " gl_Position = vec4(aPos, 1.0);\n"
                                 "}\0";

const char *vertexShaderSource2 = "#version 330 core\n"
                                  "layout (location = 0) in vec3 aPos;\n"
                                  "layout (location = 1) in vec3 aColor;\n"
                                  "out vec3 ourColor2;\n"
                                  "void main()\n"
                                  "{\n"
                                  " gl_Position = vec4(aPos, 1.0f);\n"
                                  " ourColor2 = aColor;\n"
                                  "}\0";

const char *fragmentShaderSourceO = "#version 330 core\n"
                                    "out vec4 FragColor;\n"
                                    "void main()\n"
                                    "{\n"
                                    " FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                    "}\0";

const char *fragmentShaderSourceY = "#version 330 core\n"
                                    "out vec4 FragColor;\n"
                                    "in vec3 ourColor2;\n"
                                    "void main()\n"
                                    "{\n"
                                    " FragColor = vec4(ourColor2, 1.0f);\n"
                                    "}\0";

const char *fragmentShaderSourceG = "#version 330 core\n"
                                    "out vec4 FragColor;\n"
                                    "uniform vec4 ourColor;\n"
                                    "void main()\n"
                                    "{\n"
                                    " FragColor = ourColor;\n"
                                    "}\0";

void triangleShader(unsigned int &shaderProgramO, unsigned int &shaderProgramY, unsigned int &shaderProgramG)
{
    // 编译顶点着色器
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int vertexShader2;
    vertexShader2 = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader2, 1, &vertexShaderSource2, NULL);
    glCompileShader(vertexShader2);

    // 检查顶点着色器错误
    // int success;
    // char infoLog[512];
    // glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    // if (!success)
    // {
    //     glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    //     std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
    //               << infoLog << std::endl;
    // }

    // 编译片段着色器
    unsigned int fragmentShaderO;
    fragmentShaderO = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderO, 1, &fragmentShaderSourceO, NULL);
    glCompileShader(fragmentShaderO);

    unsigned int fragmentShaderY;
    fragmentShaderY = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderY, 1, &fragmentShaderSourceY, NULL);
    glCompileShader(fragmentShaderY);

    unsigned int fragmentShaderG;
    fragmentShaderG = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderG, 1, &fragmentShaderSourceG, NULL);
    glCompileShader(fragmentShaderG);

    // 检查片段着色器错误
    // glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    // if (!success)
    // {
    //     glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    //     std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
    //               << infoLog << std::endl;
    // }

    // 着色器程序
    shaderProgramO = glCreateProgram();
    glAttachShader(shaderProgramO, vertexShader);
    glAttachShader(shaderProgramO, fragmentShaderO);
    glLinkProgram(shaderProgramO);

    shaderProgramY = glCreateProgram();
    glAttachShader(shaderProgramY, vertexShader2);
    glAttachShader(shaderProgramY, fragmentShaderY);
    glLinkProgram(shaderProgramY);

    shaderProgramG = glCreateProgram();
    glAttachShader(shaderProgramG, vertexShader);
    glAttachShader(shaderProgramG, fragmentShaderG);
    glLinkProgram(shaderProgramG);

    // 检查链接错误
    // glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    // if (!success)
    // {
    //     glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    //     std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
    //               << infoLog << std::endl;
    // }

    // 删除着色器对象
    glDeleteShader(vertexShader);
    glDeleteShader(vertexShader2);
    glDeleteShader(fragmentShaderO);
    glDeleteShader(fragmentShaderY);
    glDeleteShader(fragmentShaderG);
}