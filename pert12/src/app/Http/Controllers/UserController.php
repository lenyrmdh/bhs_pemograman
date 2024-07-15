<?php

namespace App\Http\Controllers;

use App\Models\User;
use Illuminate\Http\Request;
use illuminate\Support\Facades\DB;

class UserController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $query = DB::connection('mysql')->table('users')->get();
        return response()->json($query, 200);
    }

    public function get_user_token(Request $request, $id) {
        $user = User::where('id', $id)->get();

        if($user){
            $res['success']='true';
                    $res['message']=$user;
                    return response()->json($res);
                } else {
                    $res['success']='false';
                    $res['massage']='Cannot Find User';
                    return response()->json($res);
                }
    }
}