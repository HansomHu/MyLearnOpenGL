/**
 * @file TestAssimp.cpp
 * @author huyuexiang (huyuexiang@foxmail.com)
 * @brief Just a test for compiling with assimp and it makes no sense in fact
 * @version 0.1
 * @date 2021-06-24
 *
 */

#include <iostream>
#include <assimp/Importer.hpp> // C++ importer interface
#include <assimp/postprocess.h> // Post processing flags
#include <assimp/scene.h> // Output data structure

bool DoTheImportThing(const std::string& pFile) {
    // Create an instance of the Importer class
    Assimp::Importer importer;
    // And have it read the given file with some example postprocessing
    // Usually - if speed is not the most important aspect for you - you'll
    // probably to request more postprocessing than we do in this example.
    const aiScene* scene = importer.ReadFile(pFile,
        aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_SortByPType);
    // If the import failed, report it
    if (!scene) {
        std::cout << importer.GetErrorString() << std::endl;
        return false;
    }
    // Now we can access the file's contents.
    // DoTheSceneProcessing(scene);
    // We're done. Everything will be cleaned up by the importer destructor
    return true;
}

int main(int argc, char** argv) {
    DoTheImportThing("/path/to/the/modelfile");
    return 0;
}