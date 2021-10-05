<?php

namespace App;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Support\Facades\Log;

class Badge extends Model
{

    protected $fillable = [
        'name', 'action', 'action_count'
    ];

    public function users()
    {
        return $this->hasMany('App\User')->withTimestamps();
    }
    public function saisons()
    {
        return $this->hasMany('App\Saison')->withTimestamps();
    }

    public function unlockActionFor(User $user, Saison $saison, string $action, int $count)
    {
        $badge = $this->newQuery()
            ->where('action', $action)
            ->where('action_count', $count)
            ->first();

        if ($badge && !$badge->isUnlockedFor($user, $saison)) {
            $user->badges()->attach($badge, ['saison_id' => $saison->id]);
            Log::info("Badge: gagné: " . $badge . " par " . $user);
            return $badge;
        }
        return null;
    }


    public function isUnlockedFor(User $user, Saison $saison): bool
    {
        Log::info("Badge: liste: " . $user->badges);
        Log::info("Badge: encours: " . $this);
        return $user->badges->contains($this);
    }
}
